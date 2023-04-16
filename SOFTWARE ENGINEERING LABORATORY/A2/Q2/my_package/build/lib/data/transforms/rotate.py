# Imports
from PIL import Image
import PIL


class RotateImage(object):
    '''
        Rotates the image about the centre of the image.
    '''

    def __init__(self, degrees):
        '''
            Arguments:
            degrees: rotation degree.
        '''
        self.degrees = degrees

    def __call__(self, sample):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)
        '''
        if not isinstance(sample, PIL.Image.Image):  # if given as numpy array, then convert into PIL Image
            sample = Image.fromarray(sample)

        return sample.rotate(self.degrees)
