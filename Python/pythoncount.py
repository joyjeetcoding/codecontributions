lb = int(input("Enter the lower bound: "))
ub = int(input("Enter the upper bound: "))

chk = 0
count = 0
counttwodigit = 0

for i in range(lb, ub+1):
    for j in range(2, i//2+1):
        if i%j == 0:
            chk = chk+1
            break
    
    if chk == 0 and i != 1:
        print(i, end = " ")
        if i > 10:
            counttwodigit = counttwodigit + 1
        count = count+1
    
    chk = 0


print("\nThere are",count, end=" Prime nos")
print("\nThere are",counttwodigit, end=" two digit Prime nos")