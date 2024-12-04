# Create your models here.
import uuid

from django.db import models
from django.contrib.auth.models import PermissionsMixin
from django.contrib.auth.base_user import AbstractBaseUser
from django.utils import timezone

import datetime

from .managers import CustomUserManager

# Create your models here.
class Hospital(models.Model):
    name = models.CharField(max_length=100)
    address = models.CharField(max_length=200)
    pincode = models.CharField(max_length=6)

    def __str__(self):
        return self.name

class User(AbstractBaseUser, PermissionsMixin):

    # These fields tie to the roles!
    ADMIN = 1
    DOCTOR = 2
    PATIENT = 3

    ROLE_CHOICES = (
        (ADMIN, 'Admin'),
        (DOCTOR, 'Doctor'),
        (PATIENT, 'Patient')
    )

    PENDING = 1
    ACCEPT = 0

    STATUS_CHOICES = (
        (PENDING, 'Pending'),
        (ACCEPT, 'Accept')
    )
    
    class Meta:
        verbose_name = 'user'
        verbose_name_plural = 'users'

    uid = models.UUIDField(unique=True, editable=False, default=uuid.uuid4, verbose_name='Public identifier')
    email = models.EmailField(unique=True)
    role = models.PositiveSmallIntegerField(choices=ROLE_CHOICES, blank=True, null=True, default=3)

    # Non admin details
    first_name = models.CharField(max_length=30, blank=True)
    last_name = models.CharField(max_length=50, blank=True)
    date_joined = models.DateTimeField(auto_now_add=True)
    pending = models.PositiveSmallIntegerField(choices=STATUS_CHOICES, blank=True, null=True, default=0)
    is_staff = models.BooleanField(default=False, verbose_name='staff account')
    is_deleted = models.BooleanField(default=False)
    contact = models.CharField(max_length=12, blank=True, null=True, default='123')
    address = models.CharField(max_length=200, blank=True, null=True, default='india')
    pincode = models.CharField(max_length=50, blank=True, null=True, default='202001')
    
    # Doctor fields
    hospital = models.ForeignKey(Hospital, on_delete=models.CASCADE, related_name='hospital', blank=True, null=True)
    speciality = models.CharField(max_length=50, blank=True, null=True)


    USERNAME_FIELD = 'email'
    REQUIRED_FIELDS = []

    objects = CustomUserManager()

    def __str__(self):
        return self.email


class Appointment(models.Model):

    DONE = 1
    PENDING = 2
    REJECT = 3

    STATUS_CHOICES = (
        (DONE, 'done'),
        (PENDING, 'pending'),
        (REJECT, 'reject')
    )

    doctor = models.ForeignKey(User, on_delete=models.CASCADE, related_name='doctor')
    patient = models.ForeignKey(User, on_delete=models.CASCADE, related_name='patient')
    description = models.CharField(max_length=100)
    status = models.PositiveSmallIntegerField(choices=STATUS_CHOICES, blank=True, null=True, default=2)
    date = models.DateField(default=datetime.date.today)
    #time = models.TimeField(default=datetime.time(9,0))
    def __str__(self):
        return self.description