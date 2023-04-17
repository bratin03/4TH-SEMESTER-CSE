import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


l = 1
m = 1
inertia = m*l*l/3
g = 9.81
noise = np.random.normal(0, 2.50, 600).reshape(6, 100)


def inc_state(posi, veli, machine_torque, env, tstep=1):
    torque = machine_torque + (env*l/2)
    ang_acc = torque/inertia
    posf = posi + (veli*tstep) + ((ang_acc*tstep*tstep)/2)
    velf = veli + ang_acc*tstep
    return posf, velf


def take_action(state, env, tstep=1):
    ang_acc = 2*(-state[0] - (state[1]*tstep))/tstep**2
    torque = ang_acc*inertia
    return inc_state(state[0], state[1], torque, env, tstep)


def simulate(state_i, steps, env, tstep=1):
    states_x = np.zeros(100)
    states_y = np.zeros(100)
    state = state_i
    for i in range(steps):
        states_x[i] = state[0]
        states_y[i] = state[1]
        state = take_action(state, env[i], tstep)
    return states_x, states_y


simulation = [0, 0, 0, 0, 0, 0]

simulation[0] = simulate([0, 0], steps=100, env=noise[0], tstep=1)

co = ['orange', 'cyan', 'lightgreen', 'khaki', 'magenta', 'indigo']


# Create time array
t = np.arange(0, 100, 1)

# Define initial angular position and velocity
theta_0 = 0
omega_0 = 0

# Calculate angular position and velocity over time
theta = (simulation[0][0][t]*3.14)/180
omega = 2.5*(simulation[0][1][t]*3.14)/180

print(simulation[0][0][t])

# Define length of the rod
L = 1

# Define x and y coordinates of the rod's endpoints
x2 = np.zeros_like(theta)
y2 = np.ones_like(theta)*(-0.9)
x1 = L * np.sin(theta)
y1 = 0.8*L * np.cos(theta)

# Define figure and axes for animation
fig, ax = plt.subplots()
line, = ax.plot([], [], 'o-', lw=2)

# Define function to update the animation at each time step


def update(num):
    line.set_data([x1[num], x2[num]], [y1[num], y2[num]])
    return line,
# add a horizontal rectangle to represent the ground    
ax.add_patch(plt.Rectangle((-L, -L), 2*L, 0.1, fc='k'))



# Set limits for the axes
ax.set_xlim(-L, L)
ax.set_ylim(-L, L)

# Set axis labels and title
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_title('Motion of a Rod')

# Create animation object
ani = animation.FuncAnimation(
    fig, update, frames=len(theta), interval=1000, blit=True)
# Show animation
plt.show()