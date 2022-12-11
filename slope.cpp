// Copyright (c) 2022 Peter Sobowale All rights reserved.
//
// This program asks for the users age and tells you if you could
// date their grandchild
#include <iostream>

double SolveForY(int m, int x, int b) {
    float solveY = m * x + b;
    return solveY;
}

double SolveForY2(int m, int x, int b) {
    b = b * -1;
    float solveY2 = m * x - b;
    return solveY2;
}

double SolveForX(int y, int b, int m) {
    float solveX = y - b;
    solveX = solveX / m;
    return solveX;
}

double SolveForX2(int y, int b, int m) {
    b = b * -1;
    float solveX2 = (y + b) / m;
    return solveX2;
}

double SolveForM(int y, int b, int x) {
    float m = y - b;
    m = m / x;
    std::cout << m;
    return m;
}

double SolveForM2(int y, int b, int x) {
    b = b * -1;
    float m2 = (y + b) / x;
    return m2;
}

double SolveForB(int y, int m, int x) {
    float solveB = m * x;
    solveB = y - solveB;
    return solveB;
}

double SolveForYInt(int x1, int x2, int y1, int y2, double m) {
    double b;
    b = m * x2;
    b = y2 - b;
    return b;
}

// function that solves for m
double SolveM1(int x1, int x2, int y1, int y2) {
    double m = y2 - y1;
    double m2 = x2 - x1;
    m = m / m2;
    return m;
}

// function that solves for m(negative y1)
double SolveM2(int x1, int x2, int y1, int y2) {
    y1 = y1 * -1;
    double m = y2 + y1;
    double m2 = x2 - x1;
    m = m / m2;
    return m;
}

// function that solves for m(negative x1)
double SolveM3(int x1, int x2, int y1, int y2) {
    x1 = x1 * -1;
    double m = y2 - y1;
    double m2 = x2 + x1;
    m = m / m2;
    return m;
}

int main() {
    // initialize variables
    std::string operation, mAsAString, xAsAString, bAsAString, yAsAString;
    std::string y1AsAString, y2AsAString, x1AsAString, x2AsAString;
    int check;
    float solveB;

    // set use again to y
    std::string useAgain = "y";

    // make while loop and make it run as long as use again is y
    while (useAgain == "y") {
        // # set operation check to false and stop time to display message
        bool operationCheck = false;
        system("clear");
        std::cout << "Welcome to the world's greatest calculator!";

        // while loop that runs as long as operation check is false
        while (operationCheck == false) {
            // display choices to the user
            std::cout << "\nChoose from one of the following options:";
            std::cout << "\n \t [1]"
                      << " Solve for y -- y=mx+b \n \t "
                      << "[2] Solve for x -- x=(y-b)/m"
                      << " \n \t"
                      << " [3] Solve for m -- m=(y-b)/x \n \t "
                      << "[4] Solve for b -- b=y-mx \n \t "
                      << "[5] Solve for m -- m=(y2-y1)/(x2-x1)";

            // get operation from user
            std::cout << "\nEnter your selection: ";
            std::cin >> operation;

            // try to make sure no value or operation other than 1-5 is accepted
            try {
                check = std::stoi(operation);
                if (check >= 1 && check <= 5) {
                    operationCheck = true;
                } else {
                    system("clear");
                    continue;
                }
            } catch (std::invalid_argument) {
                system("clear");
                continue;
            }
            // select case to determine what code should run
            switch (check) {
                case 1:
                    system("clear");
                    std::cout << "******************";
                    std::cout << "\nTo solve for y, you need m, x and b.";

                    // get values for m, x and b
                    std::cout << "\nEnter a value for m: ";
                    std::cin >> mAsAString;

                    // nested try catch to make sure inputs show no errors
                    try {
                        int mUser = std::stoi(mAsAString);
                        std::cout << "Enter a value for x: ";
                        std::cin >> xAsAString;
                        try {
                            int xUser = std::stoi(xAsAString);
                            std::cout << "Enter a value for b: ";
                            std::cin >> bAsAString;
                            try {
                                int bUser = std::stoi(bAsAString);

                                // if statement to check if 0 is greater than b
                                if (0 > bUser) {
                                    double solvedY2 =
                                    SolveForY2(mUser, xUser, bUser);
                                    std::cout << "The value of y is "
                                              << solvedY2 << "."
                                              << "\n"
                                              << "The equation is y = "
                                              << mUser << "x - " << bUser << "."
                                              << "\n"
                                              << "\n";

                                } else {
                                    double solvedY =
                                    SolveForY(mUser, xUser, bUser);
                                    std::cout << "The value of y is "
                                              << solvedY << "."
                                              << "\n"
                                              << "The equation is y = "
                                              << mUser << "x + " << bUser << "."
                                              << "\n"
                                              << "\n";
                                }
                            } catch (std::invalid_argument) {
                                std::cout << "\nEnter a valid b value.";
                            }
                        } catch (std::invalid_argument) {
                            std::cout << "\nEnter a valid x value.";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nEnter a valid m value.";
                    }
                    break;

                // case 2
                case 2:
                    system("clear");
                    std::cout << "******************";
                    std::cout << "\nTo solve for x, you need y, b and m.";

                    // Get input for y, b and m
                    std::cout << "\nEnter a value for y: ";
                    std::cin >> yAsAString;

                    // try catch to make sure inputs show no errors
                    try {
                        int yUser = std::stoi(yAsAString);
                        std::cout << "Enter a value for b: ";
                        std::cin >> bAsAString;
                        try {
                            int bUser = std::stoi(bAsAString);
                            std::cout << "Enter a value for m: ";
                            std::cin >> mAsAString;
                            try {
                                int mUser = std::stoi(mAsAString);

                                // if statement to make sure m = 0 as thats
                                // an error
                                if (mUser == 0) {
                                    std::cout << "\nYour m cannot be 0.";
                                } else {
                                    // if statement to check if b is
                                    // negative or positive
                                    if (0 > bUser) {
                                        double solvedX2 =
                                        SolveForX2(yUser, bUser, mUser);
                                        std::cout << "The value of x is "
                                                  << solvedX2 << "."
                                                  << "\n"
                                                  << "The equation is y = "
                                                  << mUser << "x - "
                                                  << bUser << "."
                                                  << "\n"
                                                  << "\n";
                                    } else {
                                        double solvedX =
                                        SolveForX(yUser, bUser, mUser);
                                        std::cout << "The value of x is "
                                                  << solvedX << "."
                                                  << "\n"
                                                  << "The equation is y = "
                                                  << mUser << "x + "
                                                  << bUser << "."
                                                  << "\n"
                                                  << "\n";
                                    }
                                }
                            } catch (std::invalid_argument) {
                                std::cout << "\nEnter a valid m value";
                            }
                        } catch (std::invalid_argument) {
                            std::cout << "\nEnter a valid b value";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nEnter a valid y value.";
                    }
                    break;

                // case #3
                case 3:
                    system("clear");
                    std::cout << "******************";
                    std::cout << "\nTo solve for m, you need y, b and x.";

                    // get user input for value y, b and x
                    std::cout << "\nEnter a value for y: ";
                    std::cin >> yAsAString;

                    // try catch to make sure values have no errors
                    try {
                        int yUser = std::stoi(yAsAString);
                        std::cout << "Enter a value for b: ";
                        std::cin >> bAsAString;
                        try {
                            int bUser = std::stoi(bAsAString);
                            std::cout << "Enter a value for x: ";
                            std::cin >> xAsAString;
                            try {
                                int xUser = std::stoi(xAsAString);
                                // if statement to make sure x doesn't equal 0
                                if (xUser == 0) {
                                    std::cout << "\nYour x cannot be 0.";
                                } else {
                                    // if statement to check if b is
                                    // negative or positive
                                    if (0 > bUser) {
                                        double solvedM2 =
                                        SolveForM2(yUser, bUser, xUser);
                                        std::cout << "The value of m is "
                                                  << solvedM2 << "."
                                                  << "\n"
                                                  << "The equation is y = "
                                                  << solvedM2 << "x - "
                                                  << bUser << "."
                                                  << "\n"
                                                  << '\n';
                                    } else {
                                        double solvedM =
                                        SolveForM(yUser, bUser, xUser);
                                        std::cout << "The value of m is "
                                                  << solvedM << "."
                                                  << "\n"
                                                  << "The equation is y = "
                                                  << solvedM << "x + "
                                                  << bUser << "."
                                                  << "\n"
                                                  << '\n';
                                    }
                                }
                            } catch (std::invalid_argument) {
                                std::cout << "\nEnter a valid x value.";
                            }
                        } catch (std::invalid_argument) {
                            std::cout << "\nEnter a valid b value.";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nEnter a valid y value.";
                    }
                    break;

                // case 4
                case 4:
                    system("clear");
                    std::cout << "******************";
                    std::cout << "\nTo solve for b, you need y, m and x.";

                    // get input for values y, m and x
                    std::cout << "\nEnter a value for y: ";
                    std::cin >> yAsAString;

                    // try catch to make sure no errors in values
                    try {
                        int yUser = std::stoi(yAsAString);
                        std::cout << "Enter a value for m: ";
                        std::cin >> mAsAString;
                        try {
                            int mUser = std::stoi(mAsAString);
                            std::cout << "Enter a value for x: ";
                            std::cin >> xAsAString;
                            try {
                                int xUser = std::stoi(xAsAString);
                                // function solve for b
                                solveB = SolveForB(yUser, mUser, xUser);
                                if (0 <= solveB) {
                                    std::cout << "The value of b is "
                                              << solveB << "."
                                              << "\n"
                                              << "The equation is y = "
                                              << mUser << "x + "
                                              << solveB << "."
                                              << "\n"
                                              << "\n";
                                } else {
                                    std::cout << "The value of b is "
                                              << solveB << "."
                                              << "\n";
                                    solveB = solveB * -1;
                                    std::cout << "The equation is y = "
                                              << mUser
                                              << "x - "
                                              << solveB
                                              << "."
                                              << "\n"
                                              << "\n";
                                }
                            } catch (std::invalid_argument) {
                                std::cout << "\nEnter a valid x value.";
                            }
                        } catch (std::invalid_argument) {
                            std::cout << "\nEnter a valid m value.";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nEnter a valid y value.";
                    }
                    break;

                // case 5
                case 5:
                    system("clear");
                    std::cout << "******************";
                    std::cout << "\nTo solve for m, "
                              << "you need y1, y2, x1 and x2.";

                    // get input for values y1, y2, x1 and x2
                    std::cout << "\nEnter a value for y1: ";
                    std::cin >> y1AsAString;

                    // try catch to make sure no errors in values
                    try {
                        int y1User = std::stoi(y1AsAString);
                        std::cout << "Enter a value for y2: ";
                        std::cin >> y2AsAString;
                        try {
                            int y2User = std::stoi(y2AsAString);
                            std::cout << "Enter a value for x1: ";
                            std::cin >> x1AsAString;
                            try {
                                int x1User = std::stoi(x1AsAString);
                                std::cout << "Enter a value for x2: ";
                                std::cin >> x2AsAString;
                                try {
                                    int x2User = std::stoi(x2AsAString);
                                    if (x1User == x2User) {
                                        std::cout << "x1 and x2"
                                        << " cannot be equal.\n \n";
                                    } else {
                                        if (-1 >= y1User) {
                                            double solvedM =
                                                SolveM2(x1User, x2User,
                                                        y1User, y2User);
                                            double solvedB =
                                                SolveForYInt(x1User,
                                                            x2User, y1User,
                                                            y2User, solvedM);
                                            if (solvedB > 0) {
                                                std::cout << "The value"
                                                << " of b is "
                                                          << solvedB << "."
                                                          << "\n"
                                                          << "The equation"
                                                          << " is y = "
                                                          << solvedM
                                                          << "x + "
                                                          << solvedB
                                                          << "\n"
                                                          << "\n";
                                            } else {
                                                std::cout << "The value"
                                                << " of b is "
                                                          << solvedB << "."
                                                          << "\n";
                                                solvedB = solvedB * -1;
                                                std::cout << "The equation"
                                                << " is y = "
                                                          << solvedM
                                                          << "x - "
                                                          << solvedB
                                                          << "\n"
                                                          << "\n";
                                            }

                                        } else if (-1 >= x1User) {
                                            double solvedM =
                                                SolveM3(x1User, x2User,
                                                        y1User, y2User);
                                            double solvedB =
                                                SolveForYInt(x1User,
                                                            x2User, y1User,
                                                            y2User, solvedM);
                                            if (solvedB > 0) {
                                                std::cout << "The value"
                                                << " of b is "
                                                          << solvedB << "."
                                                          << "\n"
                                                          << "The equation"
                                                          << " is y = "
                                                          << solvedM
                                                          << "x + "
                                                          << solvedB
                                                          << "\n"
                                                          << "\n";
                                            } else {
                                                std::cout << "The value"
                                                <<" of b is "
                                                          << solvedB << "."
                                                          << "\n";
                                                solvedB = solvedB * -1;
                                                std::cout << "The equation"
                                                << " is y = "
                                                          << solvedM
                                                          << "x - "
                                                          << solvedB
                                                          << "\n"
                                                          << "\n";
                                            }

                                        } else if (-1 <= x1User) {
                                            double solvedM =
                                                SolveM1(x1User, x2User,
                                                        y1User, y2User);
                                            double solvedB =
                                                SolveForYInt(x1User,
                                                x2User, y1User,
                                                y2User, solvedM);
                                            if (solvedB > 0) {
                                                std::cout << "The value"
                                                << " of b is "
                                                          << solvedB << "."
                                                          << "\n"
                                                          << "The equation"
                                                          << " is y = "
                                                          << solvedM
                                                          << "x + "
                                                          << solvedB
                                                          << "\n"
                                                          << "\n";
                                            } else {
                                                std::cout << "The value"
                                                          << " of b is "
                                                          << solvedB << "."
                                                          << "\n";
                                                solvedB = solvedB * -1;
                                                std::cout << "The equation"
                                                << " is y = "
                                                << solvedM
                                                << "x - "
                                                << solvedB
                                                << "\n"
                                                << "\n";
                                            }
                                        }
                                    }
                                } catch (std::invalid_argument) {
                                    std::cout << "\nEnter a valid x2 value.";
                                }
                            } catch (std::invalid_argument) {
                                std::cout << "\nEnter a valid x1 value.";
                            }
                        } catch (std::invalid_argument) {
                            std::cout << "\nEnter a valid y2 value.";
                        }
                    } catch (std::invalid_argument) {
                        std::cout << "\nEnter a valid y1 value.";
                    }
                    break;
            }

            // defining useAgain to see if user wants to use again or stop
            std::cout << "\n"
                      << "Do you want to use it again? (y/n): ";
            std::cin >> useAgain;

            // if statement that stops the program if use again == n or
            // anything else
            if (useAgain == "y") {
                system("clear");
                continue;
            } else {
                system("clear");
                std::cout << "Thanks for playing!";
                break;
            }
        }
    }
}
