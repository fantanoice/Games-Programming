#include "About.h"
#include <iostream>


About::About(void)
{
}

About::~About(void)
{
}

void About::Input(void)
{
	std::cout << "Input stuff goes here.";
}

void About::Update(void)
{
	std::cout << "Update stuff goes here.";
}

void About::Render(void)
{
	std::cout << "Zorkish :: About\n";
	std::cout << "--------------------------------------------------------\n";
	std::cout << "Written by: Rachel McQueenie\n";
	std::cout << "Press ESC or Enter to return to the Main Menu\n";
}