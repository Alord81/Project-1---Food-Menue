#include <iostream>
#include <string>

using namespace std;

float Budget = 5;

enum enFood { Burger = 1, Pizza = 2, TunaSandwich = 3, Tacos = 4,
	GrilledChickenSalad = 5, BreakfastMeal = 6, GrilledCheeseSandwich = 7,
	ChickenShawarma = 8
};

enum enPayWay { Cash = 1, Card = 2 };

void shwowFoodMenue()
{
	cout << "|----------------------------------------|\n";
	cout << "|-------------- Food Menue --------------|\n";
	cout << "|----------------------------------------|\n";
	cout << "|\t(1) Burger\t\t\t |\n";
	cout << "|\t(2) Pizza\t\t\t |\n";
	cout << "|\t(3) Tuna Sandwich\t\t |\n";
	cout << "|\t(4) Tacos\t\t\t |\n";
	cout << "|\t(5) Grilled Chicken Salad\t |\n";
	cout << "|\t(6) Breakfast Meal\t\t |\n";
	cout << "|\t(7) Grilled Cheese Sandwich\t |\n";
	cout << "|\t(8) Chicken Shawarma\t\t |\n";
	cout << "|________________________________________|\n" << endl;
	cout << "chose the meal number : ";
}

enFood ReadNumberOfFood()
{
	enFood TheFood;
	short unsigned  mealNumber;
	cin >> mealNumber;

	TheFood = (enFood)mealNumber;

	return TheFood;
}

string PrintYourMealBill(enFood meal)
{

	string theMeal;
	float thePrice;

	switch (meal)
	{
	case enFood::Burger:
		theMeal = "Burger";
		thePrice = 1.0;
		break;
	case enFood::Pizza:
		theMeal = "Pizza";
		thePrice = 4.5;
		break;
	case enFood::TunaSandwich:
		theMeal = "Tuna Sandwich";
		thePrice = 0.6;
		break;
	case enFood::Tacos:
		theMeal = "Tacos";
		thePrice = 1.2;
		break;
	case enFood::GrilledChickenSalad:
		theMeal = "Grilled Chicken Salad";
		thePrice = 1.3;
		break;
	case enFood::BreakfastMeal:
		theMeal = "Breakfast Meal";
		thePrice = 0.725;
		break;
	case enFood::GrilledCheeseSandwich:
		theMeal = "Grilled Cheese Sandwich";
		thePrice = 0.3;
		break;
	case enFood::ChickenShawarma :
		theMeal = "Chicken Shawarma";
		thePrice = 0.4;
		break;
	}



	return "\n- Your Meal Is \"" + theMeal + "\"\n" + "- price : " + to_string(thePrice) + "OMR" + "\n";

}

float ThePrice(enFood meal)
{

	float thePrice;

	switch (meal)
	{
	case enFood::Burger:
		thePrice = 1.0;
		break;
	case enFood::Pizza:
		thePrice = 4.5;
		break;
	case enFood::TunaSandwich:
		thePrice = 0.6;
		break;
	case enFood::Tacos:
		thePrice = 1.2;
		break;
	case enFood::GrilledChickenSalad:
		thePrice = 1.3;
		break;
	case enFood::BreakfastMeal:
		thePrice = 0.725;
		break;
	case enFood::GrilledCheeseSandwich:
		thePrice = 0.3;
		break;
	case enFood::ChickenShawarma:
		thePrice = 0.4;
		break;
	}

	return thePrice;
}

void CashWay(enFood meal) {
	float Budget, TheRemainder;

	cout << "- Payment way : Cash.\n";
	cout << "Please Your Budget : ";
	cin >> Budget;
	cout << '\a';
	TheRemainder = Budget - ThePrice(meal);

	cout << "The Remainder : ";
	if (TheRemainder < 1)
	{
		cout << (TheRemainder * 1000) << " Baisa\b" << endl;
	}
	else
	{
		cout << TheRemainder << " OMR\b" << endl;
	}
};

void PrintPayWay(enFood meal)
{
	
	short unsigned PayWay;
	enPayWay PW;

	cout << "\n_______________________________________" << endl;
	cout << "(1) Cash\n";
	cout << "(2) Card\n";
	cout << "\nHow do you want to pay by card or cash? Chose the Number.\n";
	cin >> PayWay;

	PW = (enPayWay)PayWay;

	switch (PW)
	{
	default:
		CashWay(meal);
		break;
	case enPayWay::Cash:
		CashWay(meal);
		break;

	case enPayWay::Card:

		short unsigned PIN, ThePIN = 253;
		float TheBudget = ::Budget;
		cout << "\n- Payment way : Card.\n";
		cout << "Please Enter The PIN Number : ";
		cin >> PIN;

		cout << '\a';
		if (PIN == ThePIN)
		{
			TheBudget -= ThePrice(meal);
			if (TheBudget > 0)
			{
				cout << "\n - Your Budget : " << TheBudget << " OMR";
				cout << "\nPayment completed successfully." << endl;
			}
			else
			{
				cout << "\nError, payment failed." << endl;
			}
		}
		else
		{
			cout << "\nYou Enter Wrong PIN.." << endl;
		}
		break;

	}


}


int main()
{

	shwowFoodMenue();

	enFood theMeal;
	theMeal = ReadNumberOfFood();

	cout << PrintYourMealBill(theMeal);
	PrintPayWay(theMeal);

	cout << '\n' << ::Budget;

	return 0;
}