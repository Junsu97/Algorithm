import random


white = list(range(1, 70))
power = list(range(1, 27))

selectWhite = random.sample(white, 5)
selectPower = random.choice(power)

print(selectWhite)
print(selectPower)

