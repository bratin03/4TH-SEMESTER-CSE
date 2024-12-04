from rest_framework import permissions

class IsAuthenticatedOrPostOnly(permissions.BasePermission):

    def has_permission(self, request, view):
        if not request.user.is_authenticated: #anon call
            if request.method == 'POST':
                return True
            else:
                return False
        else:
            return True