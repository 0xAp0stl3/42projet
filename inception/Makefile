DOCKER_PATH = ./srcs/docker-compose.yml
WP_VOL = /home/mrocher/data/wordpress
DB_VOL = /home/mrocher/data/mariadb

all: create build

create:
	@sudo mkdir -p $(WP_VOL)
	@sudo mkdir -p $(DB_VOL)
	@sudo chmod 777 $(WP_VOL)
	@sudo chmod 777 $(DB_VOL)

build:
	@sudo docker-compose -f $(DOCKER_PATH) up -d --build

logs:
	@sudo docker-compose -f $(DOCKER_PATH) logs -f

re : clean all

stop:
	@sudo docker-compose -f $(DOCKER_PATH) stop

clean: stop
	@sudo docker-compose -f $(DOCKER_PATH) down -v

fclean: clean
	@sudo rm -rf $(WP_VOL)
	@sudo rm -rf $(DB_VOL)
	@sudo docker system prune -af
