

In this final Project, I chose to work on creating an Infectious Disease Simulation which modeled how the vaccinated percentage of people and the probability of disease transmission affected the length of the disease and also their effect on “Herd Immunity”. My target population size was 5900 which is around the number of students in a Cockrell school of engineering. For this Simulation, the daily interactions were fixed at 6, and my probability of disease transmission ranged from 0.1 to 1.0 at intervals of 0.1. 

Now that I have established some basic details about the project. I would like to describe my whole process of coding the project. 

The first step in this project was to write a Person class. This class included details about a person, and their state of health if they are susceptible, infected, or recovered. I used the sample output as my starting point and coded from there. Since this class was not very difficult to write it took me around an hour and a half to completely code this Class. I did run into some difficulties while writing an update() method but quickly figured out the solution was just a simple if statement.

The next step was to write the population class. This is where I ran into a big hurdle. After coding all my functions for this class, I ran the code, however, could not produce the desired output. The program was only printing out the status of one element of my vector. This baffled me, I thought that the issue had something to do with my vector creation in the Population constructor. However, after 5 hours of scouring the internet and lecture slides, I was still unable to find anything to fix this issue. After coming back to the code the next day I realized that the issue was in the vector display function and not in the constructor. This was the biggest issue I had while writing the initial iteration of the population class. I did have some other minor issues with the random_infection() function but those were easy fixes.


The next step was to incorporate contagion and vaccination in the population class. This was not very difficult to achieve for the Contagion exercise, I simply wrote a for loop which would infect people of [i+1] and [i-1] (“i” being the vector index) as long as they were susceptible. Vaccination was also fairly easy to code. For this exercise, I wrote a routine that would accept a percentage of people to vaccinate as a parameter, and then randomly choose that amount of people from the population and change their state to “vaccinate” them. 

At this point, I faced my biggest hurdle. I was not entirely sure how I would “introduce” the sick people to more random people in the population. My initial thought was that I would somehow move the elements around in the vector so that each “infected” element comes in contact with a random “susceptible” element 6 times. However, after brainstorming and using outside resources for a couple of hours I figured out the solution. I only had to infect 6 random people for each “sick” element in the population and did not have to necessarily move them around. In order to achieve this I wrote a nested loop that infected 6 random people in the population every time it came across a “sick” individual in the element. After another two hours of tweaking my code, I was finally done and happy with my results. 

After running numerous simulations, here are my results. All the data points are a mean result of 10 trials for each vaccination percentage and constant probability of transmission. 

This first graph depicts how increasing the number of vaccinated people in the population, changes the number of unvaccinated people who never got sick, thus representing“herd immunity”.

The second graph here depicts how the duration of the disease gets affected as the number of vaccinated people in the population increase.

Analysis:
The graph suggests that “herd immunity” is only achievable if a very high percentage of the population is initially vaccinated, around 95 percent. Also, the transmission probability plays a big role in determining whether people escape unaffected or not. After running countless simulations I found that as the transmission probability went higher than 0.2, it was almost impossible to achieve herd immunity. I also observed that there is a slight relationship between the number of vaccinated people and the duration of the disease. As the vaccination percentage increases, the duration of the disease goes down. However, the duration of the disease is more consistently linked with the transmission probability. This makes sense too, as the transmission probability increases, there is a higher chance for random people to get infected in the population, thus extending the course of the disease.

Limitations/Drawbacks.
Like every other simulation, my simulation also has its limitations. One of the biggest limitations of this simulation is its simplistic nature. Even though I believe that this was a difficult coding project, it is way too simple to take into account variables like demographics, daily activities, immunity of a person, mutation, climate, geographic location, etc. I did try my best to model the mutation of the disease and even wrote a separate disease class, however, I was not able to completely incorporate it into my program. Thus, due to these limitations, even though, this simulation program is not completely accurate in modeling the spread of disease, it still produces results consistent with how a disease would spread.











































