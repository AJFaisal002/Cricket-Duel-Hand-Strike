
                #include <bits/stdc++.h>
                using namespace std;
                class Hand_Cricket
                {
                    int run=0,score,sum=0,last_run;
                    static int out;
                public:
                    void set_run(int run) // Run declare from main function to class function
                    {
                        this->run=run;
                    }
                    int total_run() // Calculating total run getting from main function
                    {
                        return sum+=run;
                    }
                    bool operator<(Hand_Cricket obj) // Operator overloading function declared
                    {
                        return (score<obj.score);
                    }
                    virtual void result() // Virtual function using for displaying different result with same name
                    {
                        cout<< "Bad Luck!!!! Console Wins!!!"<<endl;
                    }
                    friend void draw_result();
                    friend void out_info(int last_run);
                    //use of friend function to use class private variable beyond the scope
                };

                class user_result:public Hand_Cricket // Declaration of derived class for result
                {
                    public:
                        void result()
                        {
                            cout<< "Congrtas!!!! You won the match!!!"<<endl;
                        }
                };

                void draw_result() //Function prototyping
                {
                    cout<< "Match Draw!!! Well Tried."<<endl;
                }

                void out_info(int last_run) //Friend Function prototyping
                {
                    if(Hand_Cricket::out==1){
                        cout<<"You're Out"<<endl;
                        cout<<"Your Total run is: "<<last_run<<endl;
                        cout<<"Now It's your turn to ball."<<endl;
                        cout<<endl;
                    }
                    else{
                        cout<<"Console Out"<<endl;
                        cout<<"Console's total run: "<<last_run<<endl;
                    }
                    Hand_Cricket::out++; // Increasing static variable value
                }

                int Hand_Cricket::out=1; //Declaring initial value of static variable

                void Rules_of_the_game()
                {
                    cout<< "Welcome to Hand Cricket game."<<endl;
                    cout<< "The rules are very simple."<<endl;
                    cout<< "You will have to bat first."<<endl;
                    cout<< "Enter any number from 1 to 6. It will count as your score." <<endl;
                    cout<< "If the number you entered is equal to the console entered number,\nthen you will be out." <<endl;
                    cout<< "Then you have to do ball." <<endl;
                    cout<< "The rules are same. But opposite to first one." <<endl;
                    cout<< "You have to enter 1 to 6, if the console entered same as yours console will be out." <<endl;
                    cout<< "The highest scorer will win the match." <<endl;
                    cout<< "\nWarning!!! If you enter number greater than 6 you will be declared out\n"<<endl;
                    cout<< "Let's start!!!\n\n" <<endl;
                }

                int main()
                {
                    Rules_of_the_game();

                    Hand_Cricket hc1,hc2; // Class object declared
                    user_result us_r;

                    srand(time(0)); // for getting random values everytime from random function
                    int first_player_run=0,AI_player_run=0;
                    //AI denotes to console's automatic input

                    again:
                    int run;
                    cout<< "Enter you number/run: ";
                    cin>>run; //User input/run while batting
                    int Random_number= (rand() % (6-1) + 1);
                    //This will display random numbers from 1 to 6

                    if(run>6 && run<1)   run=Random_number;
                    //User can't give input greater than 6 or less than 1
                    if(run!=Random_number) //Comparing Run & random function value
                    {
                        hc1.set_run(run);
                        first_player_run=hc1.total_run();
                        goto again;
                    }
                    else{ //Wiil run if user & randum function value are eqaul
                        out_info(first_player_run);
                        goto oponent;// For starting console's bat session
                    }

                    oponent:
                    cout<< "Enter you number/ball: ";
                    int ball;cin>>ball;//User input/ball while bowling
                    int Random_number2= (rand() % (6-1) + 1);

                    if(ball!=Random_number2)
                    {
                        hc2.set_run(Random_number2);
                        AI_player_run=hc2.total_run();
                        goto oponent;
                    }
                    else out_info(AI_player_run);


                    if(first_player_run==AI_player_run){
                        draw_result();
                        return 0;
                    }

                    int result= first_player_run<AI_player_run; // operator overloading
                    (result==1)?hc1.result():us_r.result(); //using virtual function & derived class

                    return 0;
                }



