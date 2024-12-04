# Create your views here.
from rest_framework import status
from rest_framework.views import APIView
from rest_framework.response import Response
from rest_framework import permissions
from rest_framework import exceptions

from .mail import (
    asmr_mail,
    new_register_mail,
    doctor_accepted,
    doctor_removed,
)

from django.db.models import Q

from .permissions import (
    IsAuthenticatedOrPostOnly,
)

from .serializers import (
    UserRegistrationSerializer,
    UserDoctorSerializer,
    UserPatientSerializer,
    UserLoginSerializer,
    DoctorListSerializer,
    DoctorListAdminSerializer,
    PatientListSerializer,
    HospitalListSerializer,
    AppointmentListSerializer,
)

from .models import (
    User, 
    Appointment,
    Hospital,
)

class AuthUserRegistrationView(APIView):
    permission_classes = (permissions.AllowAny, )

    def post(self, request):
        role = request.data['role']
        if(role == 3):
            serializer = UserPatientSerializer(data=request.data)

        elif(role == 2):
            request.data['pending'] = 1
            serializer = UserDoctorSerializer(data=request.data)
        else:
            serializer = UserRegistrationSerializer(data=request.data)

        print("requested data =", request.data)

        valid = serializer.is_valid(raise_exception=True)
        print("request is =", valid)
        if valid and role != 1:
            status_code = status.HTTP_201_CREATED

            asmr_mail(    
                "Welcome to OMCS!", 
                new_register_mail(request.data['first_name'] + " " + request.data['last_name'], role), 
                request.data['email']
            )
            print("mail sent")

            serializer.save()
            
            response = {
                'success': True,
                'statusCode': status_code,
                'message': 'User successfully registered!',
                'user': serializer.data
            }

            return Response(response, status=status_code)

class AuthUserLoginView(APIView):
    serializer_class = UserLoginSerializer
    permission_classes = (IsAuthenticatedOrPostOnly, )
 
    def post(self, request):
        serializer = self.serializer_class(data=request.data)
        user = User.objects.get(email=request.data['email'])
        valid = serializer.is_valid(raise_exception=True)

        if valid:
            if not (user.role == 2 and user.pending == 1):
                status_code = status.HTTP_200_OK

                response = {
                    'success': True,
                    'statusCode': status_code,
                    'message': 'User logged in successfully',
                    'access': serializer.data['access'],
                    'refresh': serializer.data['refresh'],
                    'authenticatedUser': {
                        'email': serializer.data['email'],
                        'role': serializer.data['role']
                    }
                }

                return Response(response, status=status_code)    
            else:
                return Response({}, status=status.HTTP_403_FORBIDDEN)

class Ping(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def get(self, request):
        try: 
            response = {
                'success': True,
                'status_code': status.HTTP_200_OK,
                'message': 'pong',
            }
            return Response(response, status=status.HTTP_200_OK)
        except:
            response = {
                'success': False,
                'status_code': status.HTTP_404_NOT_FOUND,
                'message': 'Token expired',
            }
            return Response(response, status=status.HTTP_404_NOT_FOUND)

class MeView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def get(self, request):
        user = request.user
        
        objectUser = User.objects.get(email=user.email)
        if user.role == 1:
            serializer = UserRegistrationSerializer(objectUser)
        elif user.role == 2:
            serializer = UserDoctorSerializer(objectUser)
        else:
            serializer = UserPatientSerializer(objectUser)
        response = {
            'success': True,
            'status_code': status.HTTP_200_OK,
            'message': 'Successfully fetched user',
            'me': serializer.data
        }
        return Response(response, status=status.HTTP_200_OK)
            
class DoctorListView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def get(self, request):
        user = request.user

        if user.role == 3:
            users = User.objects.all().filter(role=2).filter(pending=0)
            serializer = DoctorListSerializer(users, many=True)
            response = {
                'success': True,
                'status_code': status.HTTP_200_OK,
                'message': 'Successfully accepted doctors doctors',
                'doctors': serializer.data

            }
            return Response(response, status=status.HTTP_200_OK)
            
        elif user.role == 1:
            users = User.objects.all().filter(role=2)
            serializer = DoctorListAdminSerializer(users, many=True)
            response = {
                'success': True,
                'status_code': status.HTTP_200_OK,
                'message': 'Successfully fetched all doctors',
                'doctors': serializer.data

            }
            return Response(response, status=status.HTTP_200_OK)
        else: 
            return Response(serializer.errors, status=status.HTTP_401_UNAUTHORIZED)

class PatientListView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def get(self, request):
        user = request.user

        if user.role != 3:
            users = User.objects.all().filter(role=3)
            serializer = PatientListSerializer(users, many=True)
            response = {
                'success': True,
                'status_code': status.HTTP_200_OK,
                'message': 'Successfully fetched patients',
                'patients': serializer.data

            }
            return Response(response, status=status.HTTP_200_OK)
        else: 
            return Response(serializer.errors, status=status.HTTP_401_UNAUTHORIZED)


class UserEditView(APIView):
    permission_classes = [permissions.IsAuthenticated]

    def put(self, request, pk):
        user = request.user
        try:
            userCreate = User.objects.get(pk=pk)
        except User.DoesNotExist:
            raise exceptions.NotFound("User does not exist", code=status.HTTP_404_NOT_FOUND)

        if(user.role == 1):
            if(userCreate.role == 2):
                serializer = UserDoctorSerializer(userCreate, data=request.data)
                print("request data in serializer =", request.data)
            elif(userCreate.role == 3):
                serializer = UserPatientSerializer(userCreate, data=request.data)
            else:
                return Response(serializer.errors, status=status.HTTP_401_UNAUTHORIZED)

            valid = serializer.is_valid(raise_exception=True)
            print("request is =", valid)
            if valid:
                print(user.pending)
                print(userCreate.pending)
                if(user.pending != userCreate.pending and userCreate.pending):
                    # print("Going to send mail")
                    # print(userCreate.first_name)
                    # print(userCreate.last_name)
                    # print(userCreate.email)
                    asmr_mail(
                        "OMCS acceptance letter",
                        doctor_accepted(userCreate.first_name + " " + userCreate.last_name),
                        userCreate.email
                    )
                serializer.save()
                status_code = status.HTTP_201_CREATED

                response = {
                    'success': True,
                    'statusCode': status_code,
                    'message': 'User successfully edited',
                    'user': serializer.data
                }

                return Response(response, status=status_code)
        else:
            return Response(serializer.errors, status=status.HTTP_401_UNAUTHORIZED)
    
    def delete(self, request, pk):
        user = request.user
        try:
            userCreate = User.objects.get(pk=pk)
        except User.DoesNotExist:
            raise exceptions.NotFound("User does not exist", code=status.HTTP_404_NOT_FOUND)

        if(user.role == 1):
            userCreate.delete()
            status_code = status.HTTP_200_OK
            response = {
                'success': True,
                'statusCode': status_code,
                'message': 'User successfully deleted',
                # 'user': serializer.data
            }
            return Response(response, status=status_code)
        else:
            return Response({}, status=status.HTTP_401_UNAUTHORIZED)
    



class HospitalListView(APIView):
    serializer_class = HospitalListSerializer
    permission_classes = (permissions.IsAuthenticatedOrReadOnly, )

    def get(self, request):
        hospitals = Hospital.objects.all()
        serializer = self.serializer_class(hospitals, many=True)
        response = {
            'success': True,
            'status_code': status.HTTP_200_OK,
            'message': 'Successfully fetched hospitals',
            'hospitals': serializer.data
        }
        return Response(response, status=status.HTTP_200_OK)

    def post(self, request):
        print("Entering views post request")

        serializer = self.serializer_class(data=request.data)
        valid = serializer.is_valid(raise_exception=True)

        if valid:
            serializer.save()
            status_code = status.HTTP_201_CREATED


            response = {
                'success': True,
                'statusCode': status_code,
                'message': 'Hospital successfully registered!',
                'appointment': serializer.data
            }

            return Response(response, status=status_code)

class AppointmentListView(APIView):
    serializer_class = AppointmentListSerializer
    permission_classes = (permissions.IsAuthenticated, )

    def get(self, request):
        user = request.user
        print("Entering view get request")
        appointments = Appointment.objects.all().filter(Q(patient_id=user.id) | Q(doctor_id=user.id))
        serializer = AppointmentListSerializer(appointments, many=True)
        status_code = status.HTTP_200_OK

        response = {
                'success': True,
                'status_code': status_code,
                'message': 'Successfully fetched appointments',
                'appointments': serializer.data
        }
        return Response(response, status=status_code)

    def post(self, request):
        print("Entering views post request")
        print("request =", request.data)
        serializer = self.serializer_class(data=request.data)
        valid = serializer.is_valid(raise_exception=True)

        if valid:
            serializer.save()
            status_code = status.HTTP_201_CREATED


            response = {
                'success': True,
                'statusCode': status_code,
                'message': 'Appointment successfully registered!',
                'appointment': serializer.data
            }

            return Response(response, status=status_code)

    def put(self, request, pk):
        print("Entering views put request")
        user = request.user

        if user.role == 3:
            return Response("You do not have the permission to edit an appointment", status=status.HTTP_401_UNAUTHORIZED)
        
        try:
            appointment = Appointment.objects.get(pk=pk)
        except Appointment.DoesNotExist:
            raise exceptions.NotFound("Appointment does not exist", code=status.HTTP_404_NOT_FOUND)
        
        serializer = self.serializer_class(appointment, data=request.data)
        valid = serializer.is_valid(raise_exception=True)

        if valid:
            serializer.save()
            status_code = status.HTTP_201_CREATED

            response = {
                'success': True,
                'statusCode': status_code,
                'message': 'Appointment successfully edited',
                'appointment': serializer.data
            }

            return Response(response, status=status_code)
        return Response(serializer.errors, status=status.HTTP_400_BAD_REQUEST)