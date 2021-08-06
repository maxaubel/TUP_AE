from discord_webhook import DiscordWebhook, DiscordEmbed
from datetime import datetime
import sys

webhook_url = ""

def send_to_discord(message):
    webhook = DiscordWebhook(url=webhook_url, 
    username="TUP_AE",
    content = message)
    response = webhook.execute()

def main():
	text = " ".join(sys.argv[1:])
	send_to_discord(f"\"{text}\" a las {datetime.now()}.")

if __name__ == '__main__':
	main()
