dic = {'Sunday':3.5, 'Monday':5.4, 'Tuesday':4.5}

print(dic)

n = str(input("Enter the key in the dictionary: "))

if n in dic.keys():
    dic.pop(n)
    print(dic)
else:
    print("Not found")

