'''
    * Author: Bratin Mondal
    * Roll No: 21CS10016
    * Deparment of Computer Science and Engineering
    * Indian Institue of Technology, Kharagpur
'''

from my_package.model import ImageCaptioningModel
from my_package.model import ImageClassificationModel
from tkinter import *
from tkinter import messagebox
from functools import partial
from PIL import ImageTk, Image
from tkinter import filedialog
from functools import partial


def fileClick(clicked):
    # Define the function you want to call when the filebrowser button (Open) is clicked.
    # This function should pop-up a dialog for the user to select an input image file.
    # To have a better clarity, please check out the sample video.

    # Image type to select
    imgTypes = [('jpg Images', '*.jpg')]

    # Dialog to select Image
    imgName = filedialog.askopenfilename(
        title='Select Image', initialdir='data/imgs/', filetypes=imgTypes)

    # If no image is selected
    if (len(imgName) == 0):
        return

    # Opening the Image and setting the window size as per Image
    image = Image.open(imgName)
    root_height = image.height+50
    root_width = image.width+350
    l1.config(text="")
    l2.config(text="")
    l3.config(text="")
    l4.config(text="")
    f1.config(borderwidth=0, relief=FLAT)
    root.geometry(f"{root_width}x{root_height}")
    print(imgName)
    photo = ImageTk.PhotoImage(image)
    photo_label.config(image=photo)
    photo_label.image = photo
    eimgName.set(f"Image : {imgName[-5:]}")


def process(clicked, captioner, classifier):
    # This function will produce the required output when 'Process' button is clicked.
    # Note: This should handle the case if the user clicks on the `Process` button without selecting any image file.
    imgPath = eimgName.get()

    # Asking to choose Image first if not selected
    if (len(imgPath) == 0):
        print("Select a file first!")
        messagebox.showinfo("Warning!","Select a file first!")

    else:
        imgPath = f"data/imgs/{imgPath[-5:]}"
        image = Image.open(imgPath)
        # Generating captions , Resizing window acordingly and showing the output
        if clicked.get() == "Captioning":
            root_height = image.height+50
            root_width = image.width+1000
            root.geometry(f"{root_width}x{root_height}")
            captions = captioner(imgPath)
            l1.config(text="Top-3 Captions:", font="Helvetica 16 bold")
            l2.config(text=captions[0], font="Helvetica 12 bold")
            l3.config(text=captions[1], font="Helvetica 12 bold")
            l4.config(text=captions[2], font="Helvetica 12 bold")
            f1.config(borderwidth=6, relief=SUNKEN)
        # Generating classification , Resizing window acordingly and showing the output
        elif clicked.get() == "Classification":
            root_height = image.height+50
            root_width = image.width+600
            root.geometry(f"{root_width}x{root_height}")
            classified = classifier(imgPath)
            l1.config(text="Top-3 Classes:", font="Helvetica 16 bold")
            l2.config(
                text=f"{classified[0][1]} - {classified[0][0]*100}%", font="Helvetica 12 bold")
            l3.config(
                text=f"{classified[1][1]} - {classified[1][0]*100}%", font="Helvetica 12 bold")
            l4.config(
                text=f"{classified[2][1]} - {classified[2][0]*100}%", font="Helvetica 12 bold")
            f1.config(borderwidth=10, relief=SUNKEN)


if __name__ == '__main__':
    # Complete the main function preferably in this order:
    # Instantiate the root window.
    # Provide a title to the root window.
    # Instantiate the captioner, classifier models.
    # Declare the file browsing button.
    # Declare the drop-down button.
    # Declare the process button.
    # Declare the output label.

    # Creating instances of ImageCaptioningModel and ImageClassificationModel
    captioner = ImageCaptioningModel()
    classifier = ImageClassificationModel()

    # Creating root and giving it Title,Dimensions,
    root = Tk()
    root.title("Bratin's GUI Assignment")
    root_width = 800
    root_height = 30
    root.geometry(f"{root_width}x{root_height}")

    process_label = None

    # Entry for displaying the selected image name
    eimgName = StringVar()
    e = Entry(root, width=70, textvariable=eimgName, state="readonly")
    e.grid(row=0, column=0)

    # Button to Open dialog for Selecting Image
    b1 = Button(root, text="Open", font="Times 12 italic",
                command=partial(fileClick, TRUE))
    b1.grid(row=0, column=1)

    # OptionMenu to select between Captioner and Classifier
    option = StringVar()
    options = ["Captioning", "Classification"]
    option.set(options[0])
    dropDown = OptionMenu(root, option, *options)
    dropDown.config(font="Times 12 italic")
    dropDown.grid(row=0, column=2)

    # Button to Process the selected Image
    b2 = Button(root, text="Process",  font="Times 12 italic", command=partial(
        process, option, captioner, classifier))
    b2.grid(row=0, column=3)

    # Photo Label to display the selected Image
    photo_label = Label(root, image="")
    photo_label.grid(row=1, column=0)

    # Frame to Display the Output of the Experiment
    f1 = Frame(root)
    f1.grid(row=1, column=4)
    l0 = Label(f1, text="")
    l1 = Label(f1, text="")
    l2 = Label(f1, text="")
    l3 = Label(f1, text="")
    l4 = Label(f1, text="")
    l0.grid(row=1, column=0)
    l1.grid(row=0, column=0)
    l2.grid(row=2, column=0)
    l3.grid(row=3, column=0)
    l4.grid(row=4, column=0)

    # Mainloop
    root.mainloop()
