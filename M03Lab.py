'''
M03 Lab - Case Study: Lists, Functions, and classes

The purpose of this assignment is to apply your knowledge and skill in coding designing and utilizing classes in your Python code. 
'''
'''
Name   : M03 Lab - Case Study: Lists, Functions, and classes
Author : Eric Milliser
Date   : 4/7/2024
Version: 1
Purpose:
The purpose of this assignment is to apply your knowledge and skill in coding designing and utilizing classes in your Python code. 

Variables List
inputType (string) = input string for type
inputYear (sting) = input string for year
inputMake (string) =  input string for make
inputModel (string) =  input string for model
inputDoors (string) = input string for doors
inputRoof (string) =  input string for roof
yourVehicle (Vehicle) = vehicle class created
yourAutomobile (Automobile) = automobile class created 
'''






#class vehicle with intializing function for type
class Vehicle:
    def __init__(self, type):
        self.vehicleType = type
    def setType(self, input):
        self.type = input



#class autmobile inheriting the vehicle class
class Automobile(Vehicle):
    def __init__(self, type, year, make, model, doors, roof):
        super().__init__(type)
        self.year = year
        self.make = make
        self.model = model
        self.doors = doors
        self.roof = roof
    def outputAutomobile(self):
        print("Vehicle Type: ", self.year, "\n")
        print("Year: ", self.year , "\n")
        print("Make: ", self.make, "\n")
        print("Model: ", self.model, "\n")
        print("Number of doors: ", self.doors, "\n")
        print("Type of roof: " , self.roof, "\n")
    

    #set functions
    def setYear(self, year):
        self.year = year

    def setMake(self, make):
        self.make = make

    def setModel(self, model):
        self.model = model

    def setDoors(self, doors):
        self.doors = doors

    def setRoof(self, roof):
        self.roof = roof



#input function
def inputString(inputString, userInput):
    print(inputString)
    userInput = input()
    return userInput



#declarations
inputType = "nothing"
inputYear = "Year"
inputMake = "make"
inputModel = "Model"
inputDoors = "Doors"
inputRoof = "roof"



inputString("Enter the Type of Car: ", inputType)

yourVehicle = Vehicle(inputType)

yourVehicle.setType(inputType)

inputYear = inputString("Enter the Year: ", inputYear)
inputMake = inputString("Enter the Make: ", inputMake)
inputModel = inputString("Enter the Model: ", inputModel)
inputDoors = inputString("Enter the number of doors (2 or 4): ", inputDoors)
inputRoof = inputString("Enter the type of roof (solid or sun roof): ", inputRoof)

yourAutomobile = Automobile(yourVehicle, inputYear, inputMake, inputModel, inputDoors, inputRoof)

yourAutomobile.setYear(inputYear)
yourAutomobile.setMake(inputMake)
yourAutomobile.setModel(inputModel)
yourAutomobile.setDoors(inputDoors)
yourAutomobile.setRoof(inputRoof)



yourAutomobile.outputAutomobile()



