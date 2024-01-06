#include<iostream>
#include<vector>
using namespace std;
long long score1 = 0, score2 = 0;
void display(vector<vector<char>> &arr, string &p1, char &ch1, string &p2, char &ch2) {
    cout << endl << "\tNote :- " << ch1 << "'s :- " << p1;
    cout << endl << "\t        " << ch2 << "'s :- " << p2;
    cout << endl << endl;
    int num = 0;
    for (auto i = 0; i < 3; i++) 
    {
        cout << "\t";
        for (auto j = 0; j < 3; j++)
       {
            ++num;
            if (arr[i][j] == ch1)
            {
                cout << " " << ch1 << " ";
            }
            else if (arr[i][j] == ch2)
            {
                cout << " " << ch2 << " ";
            }
            else
            {
                cout << " " << num << " ";
            }
            if(j!=2)
            {
                cout<<'|';
            }
        }
        if(i!=2)
        {
            cout<<endl<<"\t---|---|---"<<endl;
        }
    }
    cout<<endl;
}
int vertical_check(vector<vector<char>> &arr, char &ch)
{
    int count1=0,count2=0,count3=0;
    for(auto i=0;i<3;i++)
    {
        if(arr[i][0] == ch)
        {
            ++count1;
        }
        if(arr[i][1] == ch)
        {
            ++count2;
        }
        if(arr[i][2] == ch)
        {
            ++count3;
        }
    }
    if(count1==3 || count2==3 || count3==3)
    {
        return 1;
    }
    return 0;
}
int horizontal_check(vector<vector<char>> &arr, char &ch)
{
    vector<int> count(3,0);
    for(auto i=0;i<3;i++)
    {
        for(auto j=0;j<3;j++)
        {
            if(arr[i][j]==ch)
            {
                ++count[i];
            }
        }
    }
    if(count[8]==3 || count[1]==3 || count[2]==3)
    {
        return 1;
    }
    return 0;
}
int diagonal_check(vector<vector<char>> &arr, char &ch)
{
    int count1=0,count2=0;
    for(auto i=0;i<3;i++)
    {
        if(arr[i][i] == ch)
        {
            ++count1;
        }
        if(arr[1][2-i] == ch)
        {
            ++count2;
        }
    }
    if(count1==3 || count2==3)
    {
        return 1;
    }
    return 0;
}
int match_result(vector<vector<char>> &arr, char &ch)
{
    if(vertical_check(arr, ch)==0)
    {
        if(horizontal_check(arr,ch)==0)
        {
            if(diagonal_check(arr,ch)==0)
            {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}
void Tictactoe(vector<vector<char>> &arr)
{
    string p1,p2;
    char ch1,ch2;
    int p1_index,p2_index,win=0,board_fill=0;
    cout<<endl<<" Player-1 will start the game always";
    cout<<endl<<" So, enter the palyers name accordingly\n";
    cout<<endl<<"Enter player-1 name = ";
    getline(cin,p1);
    cout<<"Enter palyer-2 name = ";
    getline(cin, p2);
    cout<<endl;
    for(int i=1;i>0;i++)
    {
        cout<<"Enter player-1 choice (X or O) = ";
        cin>>ch1;
        fflush(stdin);
        ch1=toupper(ch1);
        if(ch1=='x' || ch1=='X' || ch1=='o' || ch1=='O')
        {
            break;
        }
        else
        {
            cout<<"!! only X OR O is accepted. Enter again to continue !! \n"<<endl;
        }
    }
    ch1=='X' ? ch2='O': ch2='X';
    cout << "Now player-2 choice is = "<<ch2<<endl;
    display(arr, p1, ch1, p2, ch2);
    cout<<endl<<"!! Start the match !!"<<endl;
    while(win!=1)
    {
        for(int i=1;i>0;i++)
        {
            cout<<endl<<p1<<"'s turn: Enter any integer = ";
            cin>>p1_index;
            fflush(stdin);
            --p1_index;
            if(p1_index>=0 && p1_index<=8 && arr[p1_index/3][p1_index%3]==0)
            {
                arr[p1_index/3][p1_index%3] = ch1;
                break;
            }
            else if(p1_index>=0 && p1_index<=8 && arr[p1_index/3][p1_index%3]!=0)
            {
                cout<<"Enter only the vacant place that doesn't contain any previous mark" <<endl;
            }
            else
            {
                cout<<"!! Enter only among the numbers Shown !!" <<endl;
            }
        }
        board_fill+=1;
        display(arr, p1, ch1, p2, ch2);
        win=match_result(arr,ch1);
        cout<<endl;
        if(win==1)
        {
            cout<<"Congratulations, "<<p1<<" has won the game"<<endl;
            ++score1;
            return;
        }
        else if(board_fill==9)
        {
            cout<<"Match Draw"<<endl;
            return;
        }
        else
        {
            cout<<"Match is ongoing"<<endl;
        }
        for(int i=1;i>0;i++)
        {
            cout<<endl<<p2<<"'s turn Enter any integer = ";
            cin>>p2_index;
            fflush(stdin);
            --p2_index;
            if(p2_index>=0 && p2_index<=8 && arr[p2_index/3][p2_index%3]==0)
            {
                arr[p2_index/3][p2_index%3] = ch2;
                break;
            }
            else if(p2_index>=0 && p2_index<=8 && arr[p2_index/3][p2_index%3]!=0)
            {
                cout<<"Enter only the vacant place that doesn't contain any previous mark" <<endl;
            }
            else
            {
                cout<<"!! Enter only among the numbers Shown !!" <<endl;
            }
        }
        board_fill+=1;
        display (arr, p1, ch1, p2, ch2);
        win=match_result(arr,ch2);
        cout<<endl;
        if(win==1)
        {
            cout<<"!! Congratulations, "<<p2<<" has won the game !!"<<endl;
            ++score2;
            return;
        }
        else if(board_fill==9)
        {
            cout<<"!! Match Draw !!"<<endl;
            return;
        }
        else
        {
            cout<<"!! Match is ongoing !!"<<endl;
        }
    }
}
    int main()
    {
        string quit;
        cout<<endl;
        cout<<"\t__________________________Welcome to Tic Tac toe game_______________________________\n";
        cout<<"\t                            !! Let's start !! \n";
        while(quit.size()==0 || quit[0]=='y' || quit[0]=='Y')
        {
            vector<vector<char>> arr(3, vector<char>(3,0));
            Tictactoe(arr);
            cout<<endl<<"Want to play another game ?(Y/n) = ";
            getline(cin, quit);
            arr.clear();
            arr.shrink_to_fit();
        }
        cout<<endl<<"Come back again. Have a nice day"<<endl;
         return 0;
    }