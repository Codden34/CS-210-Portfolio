# CS-210-Portfolio
Portfolio project for CS-210 Programming Languages featuring the Corner Grocer Grocery Tracker written in C++.

# Corner Grocer Grocery Tracker

## Project Summary

The Corner Grocer Grocery Tracker was created to analyze a text file containing grocery items purchased throughout the day. The program reads each item from the input file, counts how many times it appears, and stores the results using a C++ map. The user can search for a specific item, print the frequency of every item, display the frequencies as a histogram, or exit the program. The program also creates a `frequency.dat` file so the item totals are backed up automatically. This project solved the problem of manually reviewing a long purchase list by organizing the data into a clear and usable report.

## What I Did Well

One part I did particularly well was separating the program into a class and multiple functions instead of placing all of the logic inside `main()`. Each function has a specific mission, such as loading the grocery records, searching for an item, printing all frequencies, creating the histogram, and writing the backup file. I also used a map because it allowed the program to connect each grocery item to its purchase count without creating unnecessary duplicate variables. The menu was kept direct and easy to follow, and I added input validation so the program would not continue with an invalid menu selection.

## Areas for Improvement

One improvement I could make would be allowing the item search to ignore capitalization. Currently, a user may have to enter the item exactly as it appears in the input file. Converting both the stored item and the search entry to the same capitalization would make the program easier to use. I could also improve the file-handling process by displaying more detailed error messages when the input file cannot be found or opened. Another improvement would be adding automated tests for the search, frequency calculations, and invalid menu inputs. These changes would make the program more dependable and reduce the chance of an unnoticed error.

## Challenges and Resources

The most challenging part of the project was connecting the file input, map data, and menu options so they all worked together correctly. I had to make sure the input file was read one item at a time and that repeated items increased the correct map value instead of creating separate records. Creating the histogram also required me to use the frequency count to control how many asterisks were printed for each item. I overcame these challenges by breaking the work into smaller functions, compiling the program after major changes, and testing every menu option separately. I also used the course resources, C++ documentation, and the Visual Studio debugger when I needed to track how information moved through the program.

## Transferable Skills

Several skills from this project will transfer to future course work and software projects. I gained more experience reading and writing files, organizing data with maps, creating classes, separating logic into functions, and validating user input. I also improved my ability to test a program in stages instead of waiting until the entire project was finished. The process of reading data, processing it, and producing a report can be used in inventory systems, financial programs, databases, and many other applications. The project also reinforced the importance of planning the program structure before adding more code.

## Maintainability, Readability, and Adaptability

I made the program maintainable and readable by giving the class, functions, and variables names that explain their purpose. I kept the functions focused on one responsibility and avoided placing unnecessary logic inside `main()`. The menu options are separated from the grocery-tracking calculations, which makes the program easier to update without disrupting every section. I also used comments only where they helped explain important logic, such as file processing or the histogram output. Because the grocery data is stored in a map and handled through class functions, the program could later be adapted to support additional reports, different input files, or more advanced inventory features without requiring a complete rebuild.
