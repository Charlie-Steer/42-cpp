#include "Serializer.hpp"
#include <iostream>
#include <string>

int main(void) {
	std::string str( 
		"                            _                  \n"
		"                          .' `'.__             \n"
		"                         /      \\ `'\"-,        \n"
		"        .-''''--...__..-/ .     |      \\       \n"
		"      .'               ; :'     '.  a   |      \n"
		"     /                 | :.       \\     =\\     \n"
		"    ;                   \\':.      /  ,-.__;.-;`\n"
		"   /|     .              '--._   /-.7`._..-;`  \n"
		"  ; |       '                |`-'      \\  =|   \n"
		"  |/\\        .   -' /     /  ;         |  =/   \n"
		"  (( ;.       ,_  .:|     | /     /\\   | =|    \n"
		"   ) / `\\     | `\"\"`;     / |    | /   / =/    \n"
		"     | ::|    |      \\    \\ \\    \\ `--' =/     \n"
		"    /  '/\\    /       )    |/     `-...-`      \n"
		"   /    | |  `\\    /-'    /;                   \n"
		"   \\  ,,/ |    \\   D    .'  \\                  \n"
		"jgs `\"\"`   \\  nnh  D_.-'L__nnh                 \n"
		"            `\"\"\"`                              \n"
	);

	Data image;
	image.buffer = str.c_str(),
	image.width = 47,
	image.height = 18,
	
	std::cout << "BEFORE:\n";
	std::cout << &image << "\n";
	std::cout << image.buffer;
	std::cout << image.width << "x" << image.height << "\n\n";

	uintptr_t serialized = Serializer::serialize(&image);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "AFTER:\n";
	std::cout << deserialized << "\n";
	std::cout << deserialized->buffer;
	std::cout << deserialized->width << "x" << deserialized->height << "\n\n";

	std::cout << "Is the data the same before and after serialization? ";
	if (&image == deserialized) {
		std::cout << "Yes.\n";
	} else {
		std::cout << "No.\n";
	}

	std::cout << "&image:		" << &image << "\n";
	std::cout << "serialized:	" << serialized << "\n";
	std::cout << "deserialized:	" << deserialized << "\n";

	return 0;
}


