import {Injectable} from '@angular/core';
import {Http, Response} from '@angular/http';
import {Observable} from 'rxjs/Observable';
import {Picture} from '../models/gallery.model';
import { AngularFireDatabase } from 'angularfire2/database';

import 'rxjs/add/operator/do';
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/map';
import 'rxjs/add/observable/throw';

@Injectable()
export class GalleryService {
  private picUrl = 'http://localhost:4200/assets/pictures.json';

  constructor(private http: Http, private db: AngularFireDatabase) {
  }

  public getPictures(): Observable<Picture[]> {
    return this.http.get(this.picUrl)
      .map((response: Response) => <Picture[]> response.json())
      .do(data => console.log(data))
      .catch(this.handleError);
  }

  public getPicture(id: number): Observable<Picture> {
    return this.getPictures()
      .map((pictures: Picture[]) => pictures.find(p => p.id === id));
  }

  private handleError(error: Response) {
    console.error(error);
    return Observable.throw(error.json().error || 'Server error');
  }

  public getCourses(listPath): Observable<any[]> {
    return this.db.list(listPath).valueChanges();
  }
}
