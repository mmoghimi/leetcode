class Solution(object):
    def allDigits(self, s):
        for x in s:
            if not x.isdigit():
                return False
        return True


    def checkFloat(self, s):
        if s[0] in "+-":
            s = s[1:]
        
        if not s:
            return False
        
        if "." in s:
            if len(s.split(".")) != 2:
                return False

            x, y = s.split(".")
            if not len(x) and not(len(y)):
                return False
            
            return self.allDigits(x) and self.allDigits(y)
        else:
            return self.allDigits(s)


    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower()
        
        if "e" in s:
            if len(s.split("e")) != 2:
                return False
            
            x, y = s.split("e")
            if not len(x) or not(len(y)):
                return False

            if y[0] in "+-":
                if len(y) == 1:
                    return False
                if not self.allDigits(y[1:]):
                    return False
            else:
                if not self.allDigits(y):
                    return False

            return self.checkFloat(x)
        
        return self.checkFloat(s)
                

            