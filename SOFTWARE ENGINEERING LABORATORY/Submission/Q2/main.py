#imports
from my_package.model import ImageCaptioningModel
from my_package.data import Dataset, Download
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage
import numpy as np
from PIL import Image
import os
import random


def experiment(annotation_file, captioner, transforms, outputs):
    # Create the instances of the dataset, download
    dataset = Dataset(annotation_file, transforms)
    download = Download()

    # Print image names and their captions from annotation file using dataset object
    print("Image names and captions:")
    for i, data in enumerate(dataset):
        labels=data['label']
        print(f"Image {i}: {data['path']}")
        for i,elements in enumerate(labels):
            print(f"Caption {i+1}: {elements['caption']}")
        print("\n")

    #Download images to ./data/imgs/ folder using download object
    for data in dataset:
        path = "./data/imgs/"+data['path']
        download(path, data['url'])
    # Transform the required image (roll number mod 10) and save it seperately
    for i, data in enumerate(dataset):
        if i % 10 == 6:
            image = dataset.__transformitem__("./data/imgs/"+data['path'])
            image.save(outputs)
            captions = captioner(outputs, num_captions=3)
            print("Generated captions:")
            for i, caption in enumerate(captions):
                print(f"Caption {i}: {caption}")


def get_size(path):
    img = Image.open(path)
    return img.size


def main():
    if not os.path.isdir('./Outputs'):
        os.mkdir('./Outputs')
    captioner = ImageCaptioningModel()

    print("Starting Experiment 1(The original image):")
    experiment('./data/annotations.jsonl', captioner,
               [], './Outputs/exp1.jpg')
    print("Experiment 1 Completed\n")

    print("Starting Experiment 2(Horizontally flipped original image):\n")
    experiment('./data/annotations.jsonl', captioner,
               [FlipImage('horizontal')], './Outputs/exp2.jpg')
    print("Experiment 2 Completed\n")

    print("Starting Experiment 3(Blurred image (with some degree of blurring)):\n")
    experiment('./data/annotations.jsonl', captioner,
               [BlurImage(random.randint(1, 5))], './Outputs/exp3.jpg')
    print("Experiment 3 Completed\n")

    print("Starting Experiment 4( Twice Rescaled image (2X scaled) ):\n")
    w, h = get_size('./data/imgs/6.jpg')

    experiment('./data/annotations.jsonl', captioner,
               [RescaleImage((2*w, 2*h))], './Outputs/exp4.jpg')
    print("Experiment 4 Completed\n")

    print("Starting Experiment 5( Half Rescaled image (0.5X scaled) ):\n")

    experiment('./data/annotations.jsonl', captioner,
               [RescaleImage((int(w/2), int(h/2)))], './Outputs/exp5.jpg')
    print("Experiment 5 Completed\n")

    print("Starting Experiment 6(90 degree right rotated image):\n")
    experiment('./data/annotations.jsonl', captioner,
               [RotateImage(-90)], './Outputs/exp6.jpg')
    print("Experiment 6 Completed\n")

    print("Starting Experiment 7(45 degree left rotated image):\n")
    experiment('./data/annotations.jsonl', captioner,
               [RotateImage(45)], './Outputs/exp7.jpg')
    print("Experiment 7 Completed\n")


if __name__ == '__main__':
    main()
