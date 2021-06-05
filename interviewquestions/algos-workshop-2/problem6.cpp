#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

std::vector<std::pair<int, int>> getParentheses(std::string sentence)
{
    std::vector<std::pair<int, int>> result;
    // Using a vector because unsure of input size
    std::stack<int> stack;
    for(int i = 0; i < sentence.size(); i++)
    {
        if(sentence[i] == '(')
        {
            stack.push(i);
        }
        else if(sentence[i] == ')')
        {
            if(stack.size() == 0) 
            {
                std::cout << "ERROR: Unexpected input";
                return std::vector<std::pair<int, int>>(); 
            }
            result.emplace_back(std::make_pair(stack.top(), i));
            stack.pop();
        }
    }
    if(stack.size() > 0)
    {
        std::cout << "ERROR: Missing opening parantheses";
        return std::vector<std::pair<int, int>>(); 
    } 
    // Not really necessary to reverse, just makes it look like examples given
    std::reverse(result.begin(), result.end());
    return result;
}

void test(std::string str)
{
    std::vector<std::pair<int, int>> result = getParentheses(str);
    std::cout << "[";
    for(std::pair<int, int>& pair : result)
    {
        std::cout << "(" << pair.first << "," << pair.second << "), ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    test("(())");
    test("the (first (and second ()()))");
    test("(()");
    test("(()))");
    test("((abc))");
    return 0;
}