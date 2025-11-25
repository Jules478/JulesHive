NAME=inception

all:
	@if ! grep -q vboxuser /etc/hosts; then \
		echo 127.0.0.1	mpierce.42.fr | sudo tee -a /etc/hosts; \
	fi
	@if [ ! -d "/home/vboxuser/data/mariadb" ]; then \
		mkdir -p /home/vboxuser/data/mariadb; \
	fi
	@if [ ! -d "/home/vboxuser/data/wordpress" ]; then \
		mkdir -p /home/vboxuser/data/wordpress; \
	fi
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env up --build

down:
	docker compose -f srcs/docker-compose.yml down --remove-orphans

fclean:
	docker compose -f srcs/docker-compose.yml --env-file srcs/.env down --rmi local --volumes --remove-orphans
	@if [ -d "/home/vboxuser/data" ]; then rm -rf /home/vboxuser/data; fi
	sudo sed -i '/mpierce.42.fr/d' /etc/hosts

re: fclean all