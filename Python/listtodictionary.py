l1 = []

item = int(input("Enter the no. of elementin list 1: "))

for i in range(0, item):
    ele = int(input())
    l1.append(ele)

print(l1)

l2 = []

item = int(input("Enter the no. of elementin list 2: "))

for i in range(0, item):
    ele = str(input())
    l2.append(ele)

print(l2)


print("Below is the dictionary: ")

d = zip(l1, l2)
d = dict(zip(l1, l2))

print(d)
