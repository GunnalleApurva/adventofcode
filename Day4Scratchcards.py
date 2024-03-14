s = []
while True:
    try:
        line = input()
    except EOFError:
        break
    s.append(line[8:])
    
ans = 0
for line in s:
  [left,right] = line.split('|')
  l1 = left.split()
  l2 = right.split()
  # print(l1)
  # print(l2)
  count = -1
  for win in l1 :
    if win in l2 :
      count += 1 
  if(count>-1):
    ans += 2**count

print(ans)
      

  
