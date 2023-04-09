# Imports
from PIL import Image, ImageOps
import PIL


class FlipImage(object):
    '''
        Flips the image.
    '''

    def __init__(self, flip_type='horizontal'):
        '''
            Arguments:
            flip_type: 'horizontal' or 'vertical' Default: 'horizontal'
        '''
        self.flip_type = flip_type

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        if not isinstance(image, PIL.Image.Image):  # if given as numpy array, then convert into PIL Image
            image = Image.fromarray(image)

        if self.flip_type == "horizontal":
            return ImageOps.mirror(image)
        else:
            return ImageOps.flip(image)
