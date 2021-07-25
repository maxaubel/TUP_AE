from discord_webhook import DiscordWebhook, DiscordEmbed
from datetime import datetime
import sys

webhook_url = "https://discord.com/api/webhooks/868875220121944125/jOBMe52vA4Huo6rbOfMMjnXin_DrSTgq9rLnqPHA_HNEh-1AjhrzYmeLfYhZ-JZ94DNL"

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
