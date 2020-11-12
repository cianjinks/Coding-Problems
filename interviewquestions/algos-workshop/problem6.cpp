#include <iostream>
#include <algorithm>
#include <vector>

//std::vector<std::pair<int, int>> getParentheses(std::string sentence)
//{
//    std::vector<std::pair<int, int>> result;
//    int opening = -1;
//    int closing = -1;
//    for(int i = 0; i < sentence.size(); i++)
//    {
//        if(sentence[i] == '(')
//        {
//            result.emplace_back(std::make_pair(i, -1));
//            opening++;
//        }
//        else if(sentence[i] == ')')
//        {
//            try {
//                closing++;
//                result[opening-closing] = std::make_pair(result[opening-closing].first, i);
//            } 
//            catch (const std::exception&) 
//            {
//                std::cout << "ERROR: Missing opening parantheses";
//                return std::vector<std::pair<int, int>>();
//            }
//        }
//    }
//    return result;
//}

std::vector<std::pair<int, int>> getParentheses(std::string sentence)
{
    std::vector<std::pair<int, int>> result;
    // Using a vector because unsure of input size
    std::vector<int> stack;
    int stackptr = 0;
    for(int i = 0; i < sentence.size(); i++)
    {
        if(sentence[i] == '(')
        {
            stack.emplace_back(i);
            stackptr++;
        }
        else if(sentence[i] == ')')
        {
            try {
                result.emplace_back(std::make_pair(stack[--stackptr], i));
            } 
            catch (const std::exception&) 
            {
                std::cout << "ERROR: Missing opening parantheses";
                return std::vector<std::pair<int, int>>();
            }
        }
    }
    // Not really necessary to reverse
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::vector<std::pair<int, int>> result = getParentheses("(())");
    std::cout << "[";
    for(std::pair<int, int>& pair : result)
    {
        std::cout << "(" << pair.first << "," << pair.second << "), ";
    }
    std::cout << "]" << std::endl;
    return 0;
}