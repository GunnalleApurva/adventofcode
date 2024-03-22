s1 ,s2 = input(),input()
s1 = s1[5:]
s2 = s2[10:]
s1,s2 = list(map(int,s1.split())), list(map(int,s2.split()))
print(s1,s2)
ans = 1
for i in range(len(s1)):
  count=0
  for j in range(1,s1[i]):
    if( (s1[i]-j)*j > s2[i]  ):
      count+=1 
  ans *= count
print(ans)
