def findPos(start,end,n1,n2,first):
  
  mid = (start+end)//2 
  if first:
    val = (n1-start)*start 
    if val>n2 :
      return start  
    val = (n1-mid)*mid
    if (val > n2):
      return min(mid,findPos(start+1,mid,n1,n2,True))
    else:
      return findPos(mid+1,end,n1,n2,True)
      
  else:
    val = (n1-end)*end
    if (val>n2) :
      return end 
    val = (n1-mid)*mid
    if val>n2:
      return max(mid,findPos(mid+1,end,n1,n2,False))
    else :
      return findPos(start,mid-1,n1,n2,False)

s1 ,s2 = input(),input()
s1 = int(s1[5:].replace(" ",""))
s2 = int(s2[10:].replace(" ",""))
print(s1,s2)


ans = 0
start = findPos(1,s1-1,s1,s2,True)
end = findPos(start+1,s1-1,s1,s2,False)
print(end-start+1)
