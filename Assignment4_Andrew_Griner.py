"""
Andrew Griner
6/12/2023
This code converts time in military (24 hour) to 12 hour AM/PM system
"""
def input_time():
    time = input("Enter 24-hour time in the format HH:MM: \n")  # Prompt the user to enter the time
    return time

def convert_time(time):
    hour, minute = time.split(":")  # Split the time into hour and minute components
    hour = int(hour)
    if hour == 0:  # Convert 0 hour to 12-hour format as 12 AM
        hour = 12
        am_pm = 'AM'
    elif hour < 12:  # Convert hours before 12 to AM
        am_pm = 'AM'
    elif hour == 12:  # Keep 12 hour as is, but indicate it's PM
        am_pm = 'PM'
    else:  # Convert hours greater than 12 to PM
        hour -= 12
        am_pm = 'PM'
    converted_time = f"{hour}:{minute} {am_pm}"  # Format the converted time
    return converted_time

def output_time(converted_time):
    print("Time in 12-hour format:")
    print(converted_time)

def main():
    while True:
        time = input_time()  # Get the input time
        converted_time = convert_time(time)  # Convert the time to 12-hour format
        output_time(converted_time)  # Output the converted time
        choice = input("Enter Y or y to continue, anything else quits: \n")  # Prompt for continuation
        if choice.lower() != 'y':
            break  # Break the loop if choice is not 'Y' or 'y'

if __name__ == "__main__":
    main()
