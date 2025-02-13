#include <iostream>
#include <string>

using namespace std;

class FitnessTracker{
private:
    string name;
    int stepGoal;
    int stepsTaken;
    double caloriesBurned;

public:
    FitnessTracker(string n, int goal){
        name = n;
        stepGoal = goal;
        stepsTaken = 0;
        caloriesBurned = 0;
    }

    void stepsCounter(int steps){
        if (stepsTaken >= stepGoal)
        {
            cout << "You've reached your step goal for today!\n";
            return;
        }
        if (steps > 0)
        {
            stepsTaken = stepsTaken+steps;
            caloriesBurned = caloriesBurned + steps * 0.04;
        }
        cout << stepGoal - stepsTaken << " more steps needed to achieve goal!\n";
    }

    void FeedBack(){
        cout << "User: " << name << endl;
        cout << "Steps Taken: " << stepsTaken << endl;
        cout << "Calories Burned: " << caloriesBurned << endl;
        if (stepsTaken >= stepGoal)
        {
            cout << "Goal achieved!\n";
        }
        else
        {
            cout << "Goal Not Achieved Yet!, Keep Going.\n";
        }
    }
};

int main()
{
    string name;
    int goal, steps;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter daily step goal: ";
    cin >> goal;

    FitnessTracker user(name, goal);

    int choice;
    do
    {
        cout << "\n1.Enter Steps"<< endl;
        cout<<"2.View Progress"<< endl;
        cout<<"3.Exit"<< endl;
        cout<<"Enter Option to Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter steps: ";
            cin >> steps;
            user.stepsCounter(steps);
            break;
        case 2:
            user.FeedBack();
            break;
        case 3:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
