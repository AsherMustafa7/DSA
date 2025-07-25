class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        l=0
        
        temp=[]
        for r in range(len(nums)):
            if nums[r]!=val:
                temp.append(nums[r])
        for i in range(len(temp)):
            nums[i]=temp[i]
            l+=1
        print(f"temp: {temp}")
        return l
        # Asher Mustafa