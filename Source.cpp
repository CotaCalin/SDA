#include <iostream>
#include "stack.h"
#include "queue.h"
#include <time.h>
#include <cstdlib>

using namespace std;

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
	}

	return 0;
}