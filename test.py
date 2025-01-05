import tkinter as tk
import math

# Function to continuously update the value while the button is held down
def update_value_continuous(key):
    global current_value, update_task_id
    if key == "Left":
        current_value -= 1
    elif key == "Right":
        current_value += 1
    value_text.set(f"Current Value: {current_value} degrees")
    update_meter()

    # If the button is still held down, schedule the next update
    if update_button_pressed:
        update_task_id = root.after(100, lambda: update_value_continuous(key))

# Function to handle button press
def button_press(key):
    global update_button_pressed
    update_button_pressed = True
    update_value_continuous(key)

# Function to handle button release
def button_release():
    global update_button_pressed
    update_button_pressed = False
    root.after_cancel(update_task_id)  # Cancel the update task
def update_meter():
    # Clear the current meter
    canvas.delete("meter")

    # Calculate the angle based on the current value
    angle = (current_value - min_value) / (max_value - min_value) * 180  # Scale to 0-180 degrees

    # Convert angle to radians and calculate the endpoint
    angle_rad = math.radians(angle)
    x1 = meter_x + meter_radius
    y1 = meter_y + meter_radius
    x2 = x1 + (meter_radius - 10) * math.cos(angle_rad)
    y2 = y1 - (meter_radius - 10) * math.sin(angle_rad)

    # Draw the meter arc
    canvas.create_arc(
        meter_x,
        meter_y,
        meter_x + 2 * meter_radius,
        meter_y + 2 * meter_radius,
        start=0,
        extent=angle,
        fill="green",
        outline="black",
        tags="meter"
    )

    # Draw a line to indicate the current angle
    canvas.create_line(x1, y1, x2, y2, fill="red", width=2, tags="meter")

# Initialize value-related variables
min_value = 0
max_value = 180  # Degrees
current_value = 0

# Initialize meter-related variables
meter_radius = 80
meter_x = 100
meter_y = 100

# Create the main window
root = tk.Tk()
root.title("Continuous Degree Meter")

# Create a label to display the current value
value_text = tk.StringVar()
value_label = tk.Label(root, textvariable=value_text, font=("Arial", 16))
value_label.pack(pady=20)

# Create a canvas for the meter
canvas = tk.Canvas(root, width=300, height=300)
canvas.pack()

# Create arrow buttons and bind them to button press and release functions
left_button = tk.Button(root, text="Decrease", command=lambda: button_press("Left"))
right_button = tk.Button(root, text="Increase", command=lambda: button_press("Right"))
left_button.bind("<ButtonRelease-1>", lambda event: button_release())
right_button.bind("<ButtonRelease-1>", lambda event: button_release())

left_button.pack(side=tk.LEFT, padx=20)
right_button.pack(side=tk.RIGHT, padx=20)

# Initialize the value label text
value_text.set(f"Current Value: {current_value} degrees")

# Initialize and draw the meter
update_meter()

# Variable to track button press state
update_button_pressed = False

# Variable to store the update task ID
update_task_id = None

# Run the Tkinter main loop
root.mainloop()
