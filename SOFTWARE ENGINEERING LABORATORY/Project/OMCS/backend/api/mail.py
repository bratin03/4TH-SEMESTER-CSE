from django.core.mail import send_mail
from django.conf import settings

def asmr_mail(subject, message, recipient):
    try:
        send_mail(subject, message, settings.EMAIL_HOST_USER, [recipient], fail_silently=False)
    except:
        print("Failed to send email")

def new_register_mail(user, role):
    message = "Hi " + user + ",\nYou've registered in MetBud, the online medical consultation service.\n"
    if role == 2:
        message += "Since you've registered as a doctor, you will need to wait for your account to be activated by the admin before being allowed to use the service to the fullest.\n"
    message += "Hope you have a nice time using our service.\n\n"
    message += "Thanks and regards,\nMetBuds Team"
    return message

def doctor_accepted(user):
    message = "Hi " + user + ",\nYou've registered in MetBud, the online medical consultation service.\n"
    message += "Your account has been approved by the admin. Please continue to login and use the service.\n"
    message += "Hope you have a nice time using our service.\n\n"
    message += "Thanks and regards,\nMetBuds Team"
    return message

def doctor_removed(user):
    message = "Hi " + user + ",\nYou've been removed from MetBud, the online medical consultation service.\n"
    message += "Your account has been deleted by the admin. Please register again and contact the admin to login and use the service.\n"
    message += "Hope you have a nice time using our service.\n\n"
    message += "Thanks and regards,\nMetBuds Team"
    return message
