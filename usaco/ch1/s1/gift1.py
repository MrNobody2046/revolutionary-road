
class Person(object):
    def __init__(self, name):
        self.name = name
        self.friends = []
        self.get = 0.0
        self.give = 0.0

    def __str__(self):
        return "Name:%9s,Get:%d,Paied:%d,Revenue:%d" % (self.name, self.get, self.give, self.get - self.give)


persons = {}
with open("gift1.in") as fin:
    def readline():
        return fin.readline().strip()
    NP = int(readline())
    while NP != 0:
        name = readline()
        persons[name] = Person(name)
        NP -= 1
    while True:
        host = readline()
        if not host:
            break
        pay, friend_count = tuple([int(i) for i in readline().split()])
        host = persons[host]
        if friend_count > 0:
            average_pay = round(pay / friend_count)
            host.give = average_pay * friend_count
            while friend_count != 0:
                friend_count -= 1
                friend = persons[readline()]
                friend.get += average_pay
                host.friends.append(friend)

for p in sorted(persons.values()):
    print p

