from collections import OrderedDict

def dict():
    print("------ Dictionary -----")

    # Lookup: O(1)
    #

    d = {
        'apple': 0,
        'orange': 1,
        'pineapple': 2,
        'watermelon': 3
    }

    # Iteration over (key, value) pairs
    for k, v in d.items():
        print(f"{k} -> {v}")

    # Iteration over keys
    for k in d.keys():
        print(f"Key: {k}")

    # Iteration over values
    for v in d.values():
        print(f"Value: {v}")

    # Ordered Dictionary
    od = OrderedDict()


    print("-----------------------")

def set():
    # Set is the same as as dictionary but without the (key, value) pairs just value
    # Same as in C++
    return None

def stack():
    print("-------- Stack --------")
    stack = [1, 3, 4, 7, 9, 1, 2]
    print(stack)
    stack.append(3)
    print(stack)
    print(stack.pop())
    print(stack.pop())
    print(stack)
    print("-----------------------")

def main():
    dict()
    stack()
    # ...

if __name__ == "__main__":
    main()