//
//  main.cpp
//  SDA
//
//  Created by Cota Calin on 11/06/2017.
//  Copyright © 2017 Cota Calin. All rights reserved.
//

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
#include <time.h>
#include <cstdlib>
#include <assert.h>

using namespace std;

void test()
{
    Queue Q;
    Stack S;
    
    try{
        Q.dequeue();
        assert(false);
    }
    catch(int e)
    {
    }
    
    try{
        S.pop();
        assert(false);
    }
    catch(int e)
    {
    }
    
    try{
        S.top();
        assert(false);
    }
    catch(int e)
    {
    }
    
    try{
        S.top();
        assert(false);
    }
    catch(int e)
    {
    }
    
    assert(Q.isEmpty() == true);
    assert(!Q.isEmpty() == false);
    
    assert(Q.getFirstEmpty() == 0);
    
    Q.enqueue(3);
    
    assert(Q.getFirstEmpty() == 1);
    
    
    assert(Q.isEmpty() == false);
    assert(!Q.isEmpty() == true);
    
    assert(Q.top() == 3);
    assert(Q.dequeue() == 3);
    
    assert(Q.getFirstEmpty() == 0);
    assert(Q.isEmpty() == true);
    assert(!Q.isEmpty() == false);
    
    for(int i = 0 ; i <= 51; i++)
        Q.enqueue(3);
    
    assert(Q.isFull() == true);
    assert(S.isEmpty() == true);
    assert(!S.isEmpty() == false);
    
    assert(S.isFull() == false);
    
    S.push(3);
    
    assert(S.isEmpty() == false);
    assert(!S.isEmpty() == true);
    assert(S.isFull() == false);
    
    assert(S.top() == 3);
    assert(S.pop() == 3);
    
    assert(S.isEmpty() == true);
    assert(!S.isEmpty() == false);
    assert(S.isFull() == false);
    
    
}

void populate(Queue &player1, Queue &player2, int red, int black)
{
    int randomNumber;
    int p1 = red, p2 = black;
    srand(time(0));
    
    while (p1 != 0)
    {
        randomNumber = rand() % 2 + 1;
        
        if (randomNumber == 1)
        {
            if (black != 0)
            {
                black--;
                player1.enqueue(randomNumber);
                p1--;
            }
        }
        else
        {
            if (red != 0)
            {
                red--;
                player1.enqueue(randomNumber);
                p1--;
            }
        }
    }
    
    while (p2 != 0)
    {
        randomNumber = rand() % 2 + 1;
        
        if (randomNumber == 1)
        {
            if (black != 0)
            {
                black--;
                player2.enqueue(randomNumber);
                p2--;
            }
        }
        else
        {
            if (red != 0)
            {
                red--;
                player2.enqueue(randomNumber);
                p2--;
            }
        }
    }
    
    
}

int simulate(Queue player1, Queue player2, Stack s)
{
    int turn = 1;
    int card;
    while (true)
    {
        cout << "Turn " << turn << endl;
        
        if (player1.isEmpty() && player2.isEmpty())
            return 3;
        
        if (!player1.isEmpty())
        {
            card = player1.dequeue();
            s.push(card);
            
            if (card == 1)
                cout << "Player 1 puts : Black" << endl;
            else
                cout << "Player 1 puts : Red" << endl;
            
            if (s.top() == 2)
                while (!s.isEmpty())
                {
                    card = s.pop();
                    
                    if (card == 1)
                        cout << "Player 2 gets : Black" << endl;
                    else
                        cout << "Player 2 gets : Red" << endl;
                    
                    player2.enqueue(card);
                }
            if (player1.isEmpty() && s.isEmpty())
                return 2;
        }
        if (!player2.isEmpty())
        {
            card = player2.dequeue();
            s.push(card);
            
            if (card == 1)
                cout << "Player 2 puts : Black" << endl;
            else
                cout << "Player 2 puts : Red" << endl;
            
            if (s.top() == 2)
                while (!s.isEmpty())
                {
                    card = s.pop();
                    
                    if (card == 1)
                        cout << "Player 1 gets : Black" << endl;
                    else
                        cout << "Player 1 gets : Red" << endl;
                    
                    player1.enqueue(card);
                }
            if (player2.isEmpty() && s.isEmpty())
                return 1;
        }
        turn++; 
    }
}

int main()
{
    test();
    int winner ;
    int red, black;
    Stack s;
    Queue player1, player2;
    try
    {
        int n;
        cout << "Insert the number of cards. The deck holds max 52 cards.";
        cin >> n;
        
        red = n / 2;
        black = n / 2 + n % 2;
        
        if (n > 52)
            throw 3;
        
        populate(player1, player2, red, black);
        
        winner = simulate(player1, player2, s);
        
        switch (winner)
        {
            case 1:
                cout << "Player 1 wins!\n";
                break;
            case 2:
                cout << "Player 2 wins!\n";
                break;
            case 3:
                cout << "Draw!\n";
                break;
        }
    }
    catch (int e)
    {
        if (e == 1)
            cout << "Stack is empty!";
        if (e == 2)
            cout << "Queue is empty!";
        if (e == 3)
            cout << "Too many cards!";
        if (e == 4)
            cout << "Queue is full!";
    }
    
    return 0;
}
