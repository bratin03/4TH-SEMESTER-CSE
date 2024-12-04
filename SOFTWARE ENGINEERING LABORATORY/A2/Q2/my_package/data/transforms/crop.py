# Imports
from PIL import Image
import random
import PIL
import numpy as np


class CropImage(object):
    '''
        Performs either random cropping or center cropping.
    '''

    def __init__(self, shape, crop_type='center'):
        '''
            Arguments:
            shape: output shape of the crop (h, w)
            crop_type: center crop or random crop. Default: center
        '''
        self.cropType = crop_type
        self.finalH, self.finalW = shape

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        if not isinstance(image, PIL.Image.Image):  # if given as numpy array, then convert into PIL Image
            image = Image.fromarray(image)

        OriginalW, OriginalH = image.size


        centreX = OriginalW/2 # X coordinate of center
        centreY = OriginalH/2  # Y coordinate of center
        if self.cropType != "center":  # Center Crop
            centreX = np.random.randint(self.finalW/2, OriginalW - self.finalW/2)
            centreY = np.random.randint(self.finalH/2, OriginalH - self.finalH/2)

        left = centreX - self.finalW/2
        right= centreX + self.finalW/2
        top = centreY - self.finalH/2
        bottom = centreY + self.finalH/2

        return image.crop((left,top,right,bottom))
