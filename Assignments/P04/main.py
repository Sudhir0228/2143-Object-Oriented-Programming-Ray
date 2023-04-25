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
#main.py

from dice import Die
from dice import Dice


def dieTester(die, runs=10, testType="sum"):
  """Example function to test a die or dice.
    """
  if isinstance(die, Die):
    print(f"Testing {die.sides} sided die for {runs} rolls:")
    print("    [ ", end="")
    for i in range(runs):
      print(die.roll(), end=" ")
    print("]")
  else:
    print(
      f"Rolling {len(die.dice)} {die.sides} sided die {runs} times to get the {testType} value:"
    )
    print("    [ ", end="")
    for i in range(runs):
      if testType == "avg":
        print(die.avg(), end=" ")
      elif testType == "min":
        print(die.min(), end=" ")
      elif testType == "max":
        print(die.max(), end=" ")
      else:
        print(die.sum(), end=" ")
    print("]")


if __name__ == '__main__':

  d1 = Die()
  d2 = Die(20)
  d3 = Dice(10, 5)
  d4 = Dice("8.d.20")

  dieTester(d1, 10)
  dieTester(d2, 20)
  dieTester(d3, 10, "max")
  dieTester(d3, 10, "min")
  dieTester(d3, 10, "avg")
  dieTester(d4, 20, "max")

