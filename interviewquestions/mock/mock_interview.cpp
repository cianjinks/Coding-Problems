#include <vector>
#include <string>
#include <iostream>
#include <stack>
#include <utility>
#include <algorithm>

std::string removeGreaterThan2(std::string s)
{
	std::vector<char> array(s.begin(), s.end());
	std::stack<std::pair<char, int>> stack;
	
	std::pair<char, int> currentChar(array[0], 0);
	for(int i = 0; i < array.size(); i++)
	{
		if(array[i] == currentChar.first)
		{
			currentChar.second++;
		}
		else 
		{
			if(!stack.empty() && currentChar.first == stack.top().first)
			{
				std::pair<char, int> element = stack.top();
				stack.pop();
				currentChar.second += element.second;
				//stack.push(currentChar);
				
			}
			if(currentChar.second < 3)
			{
				stack.push(currentChar);
			}
			currentChar = std::make_pair(array[i], 0);
            i--;
		}
	}

    if(!stack.empty() && currentChar.first == stack.top().first)
    {
        std::pair<char, int> element = stack.top();
        stack.pop();
        currentChar.second += element.second;
        
    }
    if(currentChar.second < 3)
    {
        stack.push(currentChar);
    }

	std::vector<char> new_string;
	while(!stack.empty())
	{
		std::pair<char, int> element = stack.top();
		stack.pop();
		for(int k = 0; k < element.second; k++)
		{
			new_string.push_back(element.first);
		}
	}
	std::reverse(new_string.begin(), new_string.end());
	return std::string(new_string.begin(), new_string.end());
}

int main()
{
    std::cout << removeGreaterThan2("AABCCCBBAAD") << std::endl;
    std::cout << removeGreaterThan2("ABDDDDCCEEEADADW") << std::endl;
    std::cout << removeGreaterThan2("LAWLDAWLLLLAWDDDD") << std::endl;
    std::cout << removeGreaterThan2("ABABABABAB") << std::endl;
    std::cout << removeGreaterThan2("AACCCAA") << std::endl;
    std::cout << removeGreaterThan2("DAADDDDCCDCAA") << std::endl;
    std::cout << removeGreaterThan2("PPFOOOFFLLPP") << std::endl;
    return 0;
}