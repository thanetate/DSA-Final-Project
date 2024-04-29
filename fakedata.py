#Thane Tate
#CSCE 3110 


#BUGS:
#i think it wants me to install these commands before i can run the program
# solution may be to implementn these commands within the python file so they execute first
# python3 -m venv faker
# source faker/bin/activate
# pip install faker

from faker import Faker
#import csv so it can write information into a file that the c++ program can read
import csv

#generate fake data function
def generate(file_path):
    fake =Faker()
    #open csv file
    with open(file_path, 'w', newline='') as csvfile:
        fieldnames=['name', 'DOB', 'street', 'city', 'state', 'zip']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

        writer.writeheader()
        for _ in range(1000000):
            writer.writerow({
                'name': fake.first_name(),
                'DOB': fake.date_of_birth().strftime("%Y-%m-%d"),
                'street': fake.street_address(),
                'city': fake.city(),
                'state': fake.state(),
                'zip': fake.zipcode()
                
            })

#main
if __name__ == "__main__":
    generate("fake_data.csv")

        