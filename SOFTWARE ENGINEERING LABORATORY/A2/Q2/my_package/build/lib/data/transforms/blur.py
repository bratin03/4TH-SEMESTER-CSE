# Imports
from PIL import Image, ImageFilter
import PIL


class BlurImage(object):
    '''
        Applies Gaussian Blur on the image.
    '''

    def __init__(self, radius):
        '''
            Arguments:
            radius (int): radius to blur
        '''
        self.radius = radius

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL Image)

            Returns:
            image (numpy array or PIL Image)
        '''
        if not isinstance(image, PIL.Image.Image): 
            image = Image.fromarray(image)  # if given as numpy array, then convert into PIL Image

        return image.filter(ImageFilter.GaussianBlur(self.radius))
