# Mock Draft
MockDraft Simulator storing and simulating realistic fantasy football drafts using Binary Search Trees, 1D arrays, 2D array, and Quick Sort algorithms 

Hello, this is my first real project and as a result first ReadMe so please bare with me

##Environment Where Code Was Ran
Visual Studio 2022 Developers Command Line Prompt
Please use similar environments for most desired results

## Description

### Functionality
- Overall the names of players and their stats are stored in both a BST based on alphabetical order of last name and an array that can be sorted by fantasy points, passing yards, or viability (See section on formulas anca calculations to understand where viability comes from)
- Able to add, remove, search for NFL players on the data structure
- Can load and save the data sets you make locally
- Able to see the pros and cons of each player
- Able to draft against a computer and choose what position you want to draft at
- Computer makes educated decisions based off of the Array sorted by viability
- AFter the draft, an evaluation of your draft is displayed showing the pros and cons of each player you picked and an overall review of how you did 

### Commands
- String stream is used to parse single lines of user input to indicate the commands
- You must follow the format exactly for each command
#### To quit
- Type 'quit' with nothing following it
- Ex: quit
#### To add a player to your data set
- It is recommended you use the command 'assist' which will prompt you each stat you must input
- However there is an 'add' command as well that allows you to add players directly but you must have all stats given on the line
- Ex: add Josh Allen QB 2000 300 13 12 2 2
#### To display the pros and cons of a certain player
- Type 'p&c' followed by the last name of the player
- Ex: p&c Allen
#### To print the players in alphabetical order
-Type 'print' with nothing else following it
-Ex: print
#### To print the players in the ranking of the category currently chosen
- Type 'ranking' with nothing else following it
- Bare in mind if no sort has been implemented yet the order will simply be the order of the players added
- Ex: ranking
#### To sort players based of a category
- Type 'sort' and either 'v' for viability, 'ff' for fantasy football points, or 'pyd' for passing yards
- Ex: sort ff
#### To search for a player
-Type 'search' followed by the last name of the player
- Ex: search Allen
#### To remove a player
-Type 'remove' followed by the last name of the player
- Ex: remove Allen
#### To load a dataset
-Type 'load' followed by the name of the file
- Ex: load filename.txt
#### To save a dataset
-Type 'save' followed by the name of the file
- Ex: save filename.txt
#### To mock draft
-Type 'mock' then the number of teams you want then the number of rounds then the pick position
-Bare in mind it is not zero index, so to have the first pick position, you type one for instance
- Ex: mock 3 4 3
#### To get the directions for all these commands
- Type 'directions' and nothing following it
- Ex: directions

## Formulas and Calculations

### Viability
Viability formulas are so that running backs and wide receivers are the most favored because of the finite talent at the position. Kickers and defenses are valued the least to simulate the need to get these positions at the end of fantasy football drafts. QB viability scores vary as highly mobile ones are actually very valuable as they have both passing and rushing abilities. TE viabilities scores will also vary depending on their touchdown and yardage usage

Consider depth is defining where they are in the actual depth chart of the team. For most positions the 'first string' or number 1 on the depth chart has the majority of the value though some teams may use two running backs meaning the second string could have value still

Numerical values are loosly based on actual fantasy scores normal apps follow. For example passing touchdowns are 4 pt, rushing and receiving touchdowns are 6 points, passing yards are 0.25 per yard, etc

#### Formula for QB Viability
(ff_points * 0.2)+(passing_yards * 0.10) + (rushing_yards * 1.01) + (passing_td * 4) + (rushing_td * 8) - fumbles - interceptions - this->depth * 4

#### Formula for RB Viability
ff_points + (rushing_yards)+(receiving_yards * 1.02) + (rushing_td * 6) + (receiving_td * 6.25) + (carries * 0.01) + (targets * 1.3) + (receptions * 1.6) - fumbles - depth * 200

#### Formula for WR and TE Viability
(ff_points) + (receiving_yards)+(rushing_yards * 1.02) + (receiving_td * 6) + (rushing_td * 6.3) + (carries * 1.3) + (receptions * 1.50) + (targets * 1.25) - fumbles - depth * 200

#### Formula for Kicker Viability
(1 * ten) + (2 * twenty) + (3 * thirty) + (4 * forty) + (5 * fifty) + (7 * fiftyPlus) - (2 * miss)

#### Formula for Defense Viability
(interceptions * 4) + (sacks * 2) + (fumbles * 4) - (points_allowed * 10)



### Eval Score
The Player.h file holds global constants for the upper and lower bounds of the average points per each position. This data was taken by taking the median score for a list of fantasy stats in the 2023 season using Fantasy Pros

Within bounds puts players in the average and anywhere outside of it is either above or below average respectively. This directly affects each players pros and cons evaluation when the command is given. Above average puts that stat line as a pro, below average puts that stat as a con and anything else goes in the average category

## Challenges
- Only a finite number of ways to sort the data, may need to change the project to make multiple BSTs on demand to cover as many stat categories wanted
- Have to manually input players, need a way to parse a certain data set automatically from the internet
- Re-sorting the data each time to fit each category or update when new players are added hurts efficiency 

