#Imports
import jsonlines
from PIL import Image
import os
import numpy as np

class Dataset(object):
    '''
        A class for the dataset that will return data items as per the given index
    '''

    def __init__(self, annotation_file, transforms=None):
        '''
            Arguments:
            annotation_file: path to the annotation file
            transforms: list of transforms (class instances)
                        For instance, [<class 'RandomCrop'>, <class 'Rotate'>]
        '''
        self.annotation_file = annotation_file
        self.transforms = transforms

        # Load the annotations into memory
        with jsonlines.open(self.annotation_file, mode='r') as reader:
            self.annotations = list(reader)

    def __len__(self):
        '''
            return the number of data points in the dataset
        '''
        return len(self.annotations)

    def __getitem__(self, idx):
        '''
            return the data items for the index idx as an object
        '''
        ann = self.annotations[idx]
        image_path = ann['file_name']
        label = ann['captions']
        url=ann['url']


        return {
            'label': label,
            'path': image_path,
            'url':url
        }

    def __transformitem__(self, path):
        '''
            return transformed PIL Image object for the image in the given path
        '''
        image = Image.open(path)

        # Apply the transforms if any
        if self.transforms:
            for t in self.transforms:
                image = t(image)

        return image
