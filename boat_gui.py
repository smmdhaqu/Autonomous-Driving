import tkinter as tk
from PIL import Image, ImageTk
from tkinter import ttk

def move_boat(event):
    key = event.keysym
    if key == "Up":
        canvas.move(boat, 0, -10)
    elif key == "Down":
        canvas.move(boat, 0, 10)
    elif key == "Left":
        canvas.move(boat, -10, 0)
    elif key == "Right":
        canvas.move(boat, 10, 0)
        
        
def display_arrow_key(key):
    text_widget.insert(tk.END, f"Arrow Key Pressed: {key}\n")
    text_widget.see(tk.END)
    
    





# Create the main window
root = tk.Tk()
root.title("Boat Control")

# Create a canvas to display the boat image
canvas = tk.Canvas(root, width=400, height=400)
#canvas.pack()
canvas.grid(row=10, column = 2)

# Load and display the boat image
image = Image.open("boat2.jpg")
boat_image = ImageTk.PhotoImage(image) # Replace "boat.png" with your boat image file
boat = canvas.create_image(200, 200, image=boat_image)


# Bind arrow key presses to the move_boat function
root.bind("<Up>", move_boat)
root.bind("<Down>", move_boat)
root.bind("<Left>", move_boat)
root.bind("<Right>", move_boat)


# Create a text widget to display arrow key presses
text_widget = tk.Text(root, height=6, width=30)
text_widget.grid(row=0, column=0, columnspan=3, padx=10, pady=10)

# Create arrow buttons and bind them to the display_arrow_key function
up_button = tk.Button(root, text="Up", command=lambda: display_arrow_key("Up"))
down_button = tk.Button(root, text="Down", command=lambda: display_arrow_key("Down"))
left_button = tk.Button(root, text="Left", command=lambda: display_arrow_key("Left"))
right_button = tk.Button(root, text="Right", command=lambda: display_arrow_key("Right"))

up_button.grid(row=1, column=1)
down_button.grid(row=3, column=1)
left_button.grid(row=2, column=0)
right_button.grid(row=2, column=2)


# Run the Tkinter main loop
root.mainloop()
