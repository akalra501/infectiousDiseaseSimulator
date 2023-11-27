#include <iostream>
#include <random>
#include <iomanip>
#include <string>
#include <vector>
using std::vector;
using namespace std;
class Disease{
public:
    int diseaseLength;
    int variants;
    float transmissionProb;
    Disease(){};
};
class Person : public Disease {
public:
    int state = 0;
    int recoveryDaysLeft;
    int age;
    string status;
    Person() {
        state = 0;
        status;
    }
    void update() {
        if (state == 1) {
            recoveryDaysLeft = recoveryDaysLeft - 1; //updates the recoveryDaysLeft if the person is still sick
            if (recoveryDaysLeft == 0) { //once the recoveryDaysLeft goes to 0, the person gets recovered
                state = -1;
            }
        }
    }
    void infect(int n) {
        recoveryDaysLeft = n;
        state = 1;
        status = "!";
    }
    bool is_susceptible() { //method to check if the person is susceptible or not
        if (state == 0) {
            return true;
        }
        else
            return false;
    }
    string status_string() {
        string a = "susceptible";
        string c = "recovered";
        if (is_susceptible()) {
            return a;
        }
        else if (state == 1) {
            return "sick";
        }
        else if (state == -1) {
            return c;
        }
    };
    bool is_stable() {
        if (state == -1) {
            return true;
        }
        else if (state == 1 or state == 0) {
            return false;
        };
    };

    void change(int x) {
        int num = x;
    }
};
//___________________________________________________________________________________________________-
class Population : public Person {
private:
    //random_device r;
    int _ncontacts_per_day{0};
    int locality{0};
public:
    int numInteractions;
    int unluckyPerson;
    vector<Person> people;
    Person newPerson;

    Population(int num) {
        for (int i = 0; i < num; i++) {
            people.push_back(newPerson);
        }
    };

    int randomPerson;
    int recoveryDaysLeft;

    void random_infection(int n) {
        recoveryDaysLeft = n;
        random_device rd;
        uniform_int_distribution<int> dist(1, people.size());
        randomPerson = dist(rd);
        people[randomPerson].infect(n);

        //people[randomPerson].state = 1;
        //people[randomPerson].recoveryDaysLeft = n;
    }

    void infectNonVaccinated() {
        random_device rando;
        uniform_int_distribution<int> dist(0, people.size());
        if (people[dist(rando)].state == 0) {
            people[dist(rando)].infect(recoveryDaysLeft);
        }
    }

    int count_infected() {
        int count = 0;
        for (int i = 0; i <= people.size(); i++) {
            if (people[i].state == 1) {
                count = count + 1;
            }

        }
        return count;

    }

    float chanceOfContagion;
    float chanceOfRandomContagion;
    float contagionProbability;
    int unlukcyBloke;

    void set_probability_of_transfer(float prob) {

        contagionProbability = prob;

        random_device randCont;
        uniform_real_distribution<float> dist(0.0, 1.0);
        chanceOfContagion = dist(randCont);
        for (int i = 0; i <= people.size(); i++) {
            if (chanceOfContagion < contagionProbability) {
                if (people[i].state == 1 && people[i + 1].state == 0 && people[i - 1].state == 0) {
                    people[i - 1].infect(recoveryDaysLeft);
                    people[i + 1].infect(recoveryDaysLeft);
                }
            }
        }
    }

    void randomInteractions(float prob) {
        random_device ran;
        uniform_real_distribution<float> dist(0.0, 1.0);
        for (int i = 0; i < people.size(); i++) {
            if (dist(ran) < prob) {
                numInteractions = 2;
                for (int j = 0; j <= numInteractions; j++) {
                    random_device rdl;
                    uniform_int_distribution<int> dist(0, people.size());
                    unlukcyBloke = dist(rdl);
                    if (people[i].state == 1) {
                        if (people[unlukcyBloke].state == 0  /*people[unlukcyBloke].state == -1*/) {
                            people[unlukcyBloke].infect(recoveryDaysLeft);
                        }
                    }
                }

            }
        }
    }

    void display() {
        for (int i = 0; i <= people.size(); i++) {
            cout << people[i].status << " ";
        }
    }

    void displayState() {
        for (int i = 0; i <= people.size(); i++) {
            cout << people[i].state << " ";
        }
    }

    //void method to vaccinate a certain percentage of people.
    void vaccinate(float percentVax) {
        float vaxCounter = percentVax * people.size();
        random_device vaxxer;
        uniform_real_distribution<float> dist(0, people.size());
        while (vaxCounter >= 0.0) {
            if (people[dist(vaxxer)].state != 1) {
                people[dist(vaxxer)].status = "v";
                people[dist(vaxxer)].state = 3;
                vaxCounter--;
            }
        }
    }

    void update() {
        for (int i = 0; i <= people.size(); i++) {
            if (people[i].state == 1) {
                //updates the recoveryDaysLeft if the person is still sick
                people[i].recoveryDaysLeft = people[i].recoveryDaysLeft - 1;
                //once the recoveryDaysLeft goes to 0, the person gets recovered
                if (people[i].recoveryDaysLeft == 0) {
                    people[i].state = -1;
                }
            }
            for (int i = 0; i <= people.size(); i++) {
                if (people[i].state == 0) {
                    people[i].status = "?";
                } else if (people[i].state == 1) {
                    people[i].status = "!";
                } else if (people[i].state == -1) {
                    people[i].status = "rec";
                } else if (people[i].state == 3) {
                    people[i].status = "v";
                }
            }
        }
    }

    float count = 0.;
    float percent;
    float percentNeveraffected() {
        for (int i = 0; i < people.size();i++){
            if(people[i].state == 0 ){
                count ++;
            }
        }
        return count;
    }
    float neverVaxedPeople=0;
    float peopleNeverVacced() {
        for (int i = 0; i < people.size(); i++) {
            if (people[i].state == 0) {
                neverVaxedPeople ++;
            }
        }
        return neverVaxedPeople;

    }
};
int main() {
    float peopleNeverVacced;
    int npeople=5900;
    float prob = 0.8; //this prob is variable and was changed for the simulations.
    //cout << "Size of population? ";
    //cin >> npeople;
    cout << "Started...";
    Population population(npeople);
    population.random_infection(10);
    population.vaccinate(0.85);//this percentage is variable and was changed for the simulations.
    //cout << "In step " << setw(3) << "1"
           // << " #sick: " << population.count_infected()
        //<< setw(3) << " : ";
    //population.count_infected();
    //population.update();
    peopleNeverVacced = population.peopleNeverVacced();
    cout << "people never vaccinated:" << peopleNeverVacced;
    cout << endl;
   // population.display();
  //  population.displayState();
    cout << endl;


    int step2 = 2;
    for (; ; step2++) {
        //population.set_probability_of_transfer(0.5);
        population.update();
        population.set_probability_of_transfer(prob);
        population.randomInteractions(prob);
        //cout << "In step " << setw(3) << step2
           //  << " #sick: " << population.count_infected()
            // << setw(3) << " : ";
        population.count_infected();
       // population.display();
       // population.displayState();

        //cout << endl;
        if (population.count_infected() == 0)
            break;
    }
    float b = population.percentNeveraffected();
    cout << "Percent never affected:" << (b/peopleNeverVacced)*100;
    cout << "\n";
    cout << "Disease ran its course by step " << step2 << '\n';
    return 0;

}

