import pygame
import math

# define some colors
BLACK = (0, 0, 0)
RED  = (255, 0, 0)
WHITE = (255, 255, 255)
GREEN = (0, 255, 0)

# initialize Pygame
pygame.init()

# set the dimensions of the game window
screen_width = 800
screen_height = 600
screen = pygame.display.set_mode((screen_width, screen_height))

# set the title of the game window
pygame.display.set_caption("Car Game")

# create a clock object to control the frame rate
clock = pygame.time.Clock()

# define the path as an array of x-y coordinates
path = []
path.append([100, 100])

# add a straight line
for i in range(7):
    path.append([100 + i*20, 180])

# add a roundabout
center_x, center_y = 200, 250
radius = 50
for i in range(14):
    angle = i * math.pi / 7
    x = center_x + math.cos(angle) * radius
    y = center_y + math.sin(angle) * radius
    path.append([x, y])

# add another straight line
for i in range(4):
    path.append([300, 200 + i*30])

# add a final curve
center_x, center_y = 300, 340
radius = 40
for i in range(4):
    angle = (i + 1) * math.pi / 6
    x = center_x + math.cos(angle) * radius
    y = center_y + math.sin(angle) * radius
    path.append([x, y])
    
path.append([300, 340])
# set the starting position and angle of the car
car_pos = path[0]
car_angle = 0

# set the speed and turn rate of the car
car_speed = 5
car_turn_rate = 5

# set the target as the second point on the path
target = 1

# set the threshold distance to the last point on the path
threshold = 10

def rotate_point(point, angle, origin):
    ox, oy = origin
    px, py = point
    qx = ox + math.cos(angle) * (px - ox) - math.sin(angle) * (py - oy)
    qy = oy + math.sin(angle) * (px - ox) + math.cos(angle) * (py - oy)
    return qx, qy

# main game loop
running = True
while running:
    # handle events
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # check if the car has reached the current point on the path
    if math.dist(car_pos, path[target]) < car_speed:
        # select the next point on the path as the target
        target = (target + 1) % len(path)

    # calculate the next position and angle of the car
    next_pos = path[target]
    next_angle = math.atan2(next_pos[1] - car_pos[1], next_pos[0] - car_pos[0])
    if next_angle < 0:
        next_angle += 2 * math.pi
    angle_diff = next_angle - car_angle
    if angle_diff > math.pi:
        angle_diff -= 2 * math.pi
    if angle_diff < -math.pi:
        angle_diff += 2 * math.pi
    turn_angle = min(abs(angle_diff), car_turn_rate)
    if angle_diff < 0:
        turn_angle = -turn_angle
    car_angle += turn_angle
    print(car_angle)
    turn_angle_rad = turn_angle * math.pi / 180
    car_pos = rotate_point(car_pos, turn_angle_rad, car_pos)
    car_pos = (car_pos[0] + car_speed * math.cos(car_angle), car_pos[1] + car_speed * math.sin(car_angle))

    # clear the screen
    screen.fill(WHITE)

    # draw the path
    pygame.draw.lines(screen, BLACK, False, path, 2)

    # draw the car
    car_surface = pygame.Surface((35, 15))
    car_surface.fill(GREEN)
    car_rect = car_surface.get_rect(center=car_pos)
    rotated_car_surface = pygame.transform.rotate(car_surface, -car_angle * 180 / math.pi)
    screen.blit(rotated_car_surface, rotated_car_surface.get_rect(center=car_rect.center))

    # update the display
    pygame.display.flip()

    # check if the car is close to the last point on the path
    if math.dist(car_pos, path[-1]) < threshold:
        running = False

    # limit the frame rate
    clock.tick(30)
