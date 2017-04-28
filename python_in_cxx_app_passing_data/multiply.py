def multiply(a,b):
    print("Will compute", a, "times", b)
    c = 0
    for i in range(0, a):
        c = c + b
    return c

class myclass:
    def __init__(self, value):
        self.value = value;
        
    def getvalue(self):
        return self.value;

val = 10;
mc1 = myclass(val);

print("the value is {}".format(mc1.getvalue()))


