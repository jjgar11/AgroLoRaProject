from flask import Blueprint, request, jsonify
from .storage import save_to_csv

bp = Blueprint("routes", __name__)

@bp.route("/data", methods=["POST"])
def receive_data():
    data = request.get_json()
    
    required_fields = {"id", "ts", "t", "h", "p", "m"}
    if not data or not required_fields.issubset(data):
        return jsonify({"error": "Datos incompletos"}), 400
    
    save_to_csv(data)
    return jsonify({"status": "ok"}), 200
