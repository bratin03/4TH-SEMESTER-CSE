# Imports
from PIL import Image
import PIL


class RescaleImage(object):
    '''
        Rescales the image to a given size.
    '''

    def __init__(self, output_size):
        '''
            Arguments:
            output_size (tuple or int): Desired output size. If tuple, output is
            matched to output_size. If int, smaller of image edges is matched
            to output_size keeping aspect ratio the same.
        '''
        self.size = output_size

    def __call__(self, image):
        '''
            Arguments:
            image (numpy array or PIL image)

            Returns:
            image (numpy array or PIL image)

            Note: You do not need to resize the bounding boxes. ONLY RESIZE THE IMAGE.
        '''
        if not isinstance(image, PIL.Image.Image):
            image = Image.fromarray(image) # if given as numpy array, then convert into PIL Image

        if isinstance(self.size, tuple):
            result = image.resize(self.size)

        elif isinstance(self.size, int):
            h, w = image.size
            if h > w:
                result = image.resize((int(h*self.size/w), self.size))
            else:
                result = image.resize((self.size, int(w*self.size/h)))

        return result
