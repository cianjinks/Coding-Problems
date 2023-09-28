# Stack
# HashSet
# HashMap
# Sorting

from queue import Queue

def main():
    print("Stack...")
    stack = [2, 3]
    stack.append(5)
    a = stack.pop()
    print(a)
    stack.append(6)
    a = stack.pop()
    print(a)
    a = stack.pop()
    print(a)
    print()

    print("Queue...")
    q = Queue()
    q.put(5)
    q.put(2)
    q.put(3)
    print(q.get())
    print(q.get())
    print()

    print("Set...")
    set = {1, 4, 2}
    print(set)
    set.add(3)
    print(set)
    print(len(set))
    print()

    print("HashMap...")
    dict = {"a": 5, "b": 2}
    print(dict)
    print()

    list = [123, 123, 1, 2, 3]
    list.sort()
    print(list)

if __name__ == "__main__":
    main()