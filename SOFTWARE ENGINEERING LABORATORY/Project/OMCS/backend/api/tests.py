from django.test import TestCase
from api.models import User, Hospital, Appointment
# Create your tests here.

class OMCSTestCase(TestCase):
    def create_user(self):
        User.objects.create(email="admin@omcs.com", password="a", role=1)
        User.objects.create(email="doctor@omcs.com", password="a", role=2)
        User.objects.create(email="patient@omcs.com", password="a", role=3)

        Hospital.objects.create(name="BC Roy", address="IIT KGP", pincode="732105")
        
    def test_book_appointment(self):

        doctor = User.objects.filter(email="doctor@1.com").first()
        patient = User.objects.filter(email="patient@1.com").first()

        appointment = Appointment.objects.create(doctor_id=doctor, patient_id=patient, description="Scheduled appointment", status=2)
        # appointment.update(doctor=doctor, patient=patient, description="Scheduled appointment", status=1)