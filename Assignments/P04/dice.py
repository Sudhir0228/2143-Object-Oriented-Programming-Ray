""""
              
 Author:           Sudhir Ray
 Email:            raysudhir30@gmail.com
 Label:            P04
 Title:            Roll Them Bones!
 Course:           CMPS 2143
 Semester:         Spring 2023
 
 Description:
      This program implements Dice and Die classes.

 Usage:
      N/A
 
 Files:  
       main.py
       dice.py

"""
#dice.py

import random
import sys
from rich import print

"""
 Class Die

Description:
   Implementation of the Die class.

Methods:
     __init__(self, sides)
     roll(self)
     __str__(self)
   
"""

class Die(object):

  """
     __init__
     Description:
         This is a constructor for class Die.
     Returns:
         N/A
    """

  def __init__(self, sides=None):
    if not sides:
      self.sides = 6
    else:
      self.sides = sides
  """
     roll
     Description:
         Shuffles the values of the rolls.
     Returns:
         the value of the roll after shuffling.
  """

  def roll(self):
    values = [x for x in range(self.sides)]
    random.shuffle(values)
    return values[0] + 1

  """
     __str__
     Description:
         This is similar to ostream overloading in c++. Formats how we want to print.
     Returns:
         Die as a string
  """

  def __str__(self):
    return f"[sides: {self.sides}]"


"""
 Class Dice

Description:
    Implementation of Dice class.

Methods:
     __init__(self, n, s)
     sum(self)
     __str__(self)
     max(self)
     min(self)
     avg(self)
     roll(self)   
"""


class Dice:

  """
     __init__
     Description:
         This is a constructor for class Dice.
     Returns:
         N/A
  """

  def __init__(self, sides=None, num_dice=1):
    if (sides == None):
      print("Need to pass in sides!!!")
      sys.exit()

    ## sides
    self.sides = sides

    self.dice = []

    for die in range(num_dice):
      self.dice.append(Die(sides))

  """
     sum
     Description:
            Adds all the number in each rolls.
     Returns:
         The sum of rolls.
  """

  def sum(self):
    total = 0
    for d in self.dice:
      total += d.roll()

    return total

  """
     __str__
     Description:
         This is similar to ostream overloading in c++. Formats how we want to print.
     Returns:
         Dice as a string
  """

  def __str__(self):
    s = "Dice:[\n"
    for d in self.dice:
      s = s + str(d)
    s = s + "\n]\n"
    return s
"""
     max
     Description:
            Appends each roll in a list and returns the max among them.
     Returns:
         The maximum of rolls.
  """
  def max(self) -> int:
    results = []
    for i in self.dice:
      results.append(i.roll())
    return max(results)
"""
     min
     Description:
            Appends each roll in a list and returns the min among them.
     Returns:
         The minimum of rolls.
"""
  def min(self) -> int:
    results = []
    for i in self.dice:
      results.append(i.roll())
    return min(results)
"""
     avg
     Description:
            Appends each roll in a list and returns the average among them.
     Returns:
         The average of rolls.
"""
  def avg(self) -> int:
    results = []
    for i in self.dice:
      results.append(i.roll())
    return sum(results) / len(results)

"""
     roll
     Description:
            Calls the function based on the input.
     Returns:
         The value according to input (max, min, avg, sum).
"""
  def roll(self, rollType=None):
    if rollType == 'max':
      return self.max()
    elif rollType == 'min':
      return self.min()
    elif rollType == 'avg':
      return self.avg()
    else:
      return self.sum()


if __name__ == '__main__':
  D1 = Die()
  D2 = Die(10)

  print(D1)
  print(D2)
  print()
  d3 = Dice(10, 5)

